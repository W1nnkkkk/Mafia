#include "roomserver.h"
#include "jsoncontroller.h"
#include <ctime>

#define ROOM_NAME 1
#define PASSWORD 2
#define WHO 2
#define MESSAGE 2
#define COMMAND 3
#define STATE 3
#define FOR_WHO 3
#define REQ_TYPE 0

#define ALIVE_STATE "alive"
#define DEATH_STATE "death"

RoomServer::RoomServer(QObject *parent)
    : QTcpServer{parent}
{
    if (listen(QHostAddress::Any, 2424))
    {
        qDebug() << "listen...";
    }
    else
    {
        qDebug() << "Ошибка прослушивания";
    }
}

void RoomServer::onReadyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        QJsonDocument request;
        in >> request;
        QVector<QVariant> req = JsonController::getRequestFromClient(request);
        roomName = req[ROOM_NAME].toString();
        thisPlayer = socket;
        qDebug() << roomName;

        if (chatRooms.contains(roomName) && (req[REQ_TYPE].toString() == "connection"))
        {
            chatRooms[roomName].playersCount++;
            chatRooms[roomName].clients_num.insert(chatRooms[roomName].playersCount, socket);
            chatRooms[roomName].clients_role.insert(chatRooms[roomName].playersCount, roles[0]);
            chatRooms[roomName].clients_state.insert(chatRooms[roomName].playersCount, ALIVE_STATE);
            chatRooms[roomName].playersNO = chatRooms[roomName].playersCount;

            sendToClient(JsonController::formConnectResponse("connection"
                                                             , roomName, chatRooms[roomName].playersNO));
        }
        else if (!chatRooms.contains(roomName) && (req[REQ_TYPE].toString() == "create"))
        {
            Room newRoom;
            chatRooms.insert(roomName, newRoom);
            sendToClient(JsonController::formCreateResponse("create", "room created"));
        }
        else
        {
            execRequest(req);
        }

    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void RoomServer::incomingConnection(qintptr handle)
{
    QTcpSocket *clientSocket = new QTcpSocket(this);
    clientSocket->setSocketDescriptor(handle);

    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void RoomServer::sendToClient(QJsonDocument doc)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly | QIODevice::ReadOnly);
    out.setVersion(QDataStream::Qt_6_2);
    qDebug() << doc["responseType"].toString();
    out << doc;
    if ((doc["responseType"].toString() != "create") && (doc["responseType"].toString() != "connection")){
        for (int i = 1; i <= chatRooms[roomName].playersCount; ++i) {
            chatRooms[roomName].clients_num.value(i)->write(data);
        }
    }
    else
    {
        thisPlayer->write(data);
    }
}

void RoomServer::execRequest(QVector<QVariant> commands)
{
    if (commands[REQ_TYPE].toString() == "message")
    {
        sendToClient(JsonController::formResponseToClient(commands[REQ_TYPE].toString(), chatRooms[roomName].playersNO,
                                                          chatRooms, commands[MESSAGE].toString()));
    }
}
