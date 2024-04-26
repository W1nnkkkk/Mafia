#include "databaseserver.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "jsoncontroller.h"




DataBaseServer::DataBaseServer(QObject *parent)
    : QTcpServer(parent)
{
    if(listen(QHostAddress::Any, 2323)){
        qDebug() << "Listening...";
    }
    else {
        qDebug() << "Error while starting: " << errorString();
    }

    usersDb = QSqlDatabase::addDatabase("QPSQL");

    usersDb.setHostName("127.0.0.1");
    usersDb.setDatabaseName("Mafia");
    usersDb.setUserName("postgres");
    usersDb.setPassword("your pass");

    if (usersDb.open()){
        qDebug() << "Opened";

    } else {
        qDebug() << "Error = " << usersDb.lastError().text();
        exit(-1);
    }
}

void DataBaseServer::onReadyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        QJsonDocument request;
        in >> request;
        QVector<QString> req = JsonController::getRequestFromClient(request);
        executeRequest(req);
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void DataBaseServer::onDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    socket->close();
    socket->deleteLater();
}

void DataBaseServer::incomingConnection(qintptr handle)
{
    QTcpSocket* socket = new QTcpSocket;
    socket->setSocketDescriptor(handle);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

void DataBaseServer::sendToClient(QJsonDocument jsonDoc)
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    dataByteArray.clear();
    QDataStream out(&dataByteArray, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << jsonDoc;
    socket->write(dataByteArray);
}

void DataBaseServer::executeRequest(QVector<QString> reqLoginPass)
{
    if (reqLoginPass[REQUEST] == "register")
    {
        QSqlQuery query(usersDb);
        query.prepare("SELECT * FROM \"Users\".get_user_data(:login, :pass)");
        query.bindValue(":login", reqLoginPass[LOGIN]);
        query.bindValue(":pass", reqLoginPass[PASSWORD]);

        if (!query.exec() || !query.next()) {
            qDebug() << query.lastError();
        } else {
            sendToClient(JsonController::formResponse(REGISTER_TYPE,
                                                      query.value(0).toBool(),
                                                      query.value(1).toString(),
                                                      query.value(2).toInt(),
                                                      query.value(3).toInt()));
        }

    }
    else if(reqLoginPass[REQUEST] == "login")
    {
        QSqlQuery query(usersDb);
        query.prepare("SELECT * FROM \"Users\".check_loginning(:login, :pass)");
        query.bindValue(":login", reqLoginPass[LOGIN]);
        query.bindValue(":pass", reqLoginPass[PASSWORD]);

        if (!query.exec() || !query.next()) {
            qDebug() << query.lastError();
        } else {
            sendToClient(JsonController::formResponse(LOGIN_TYPE,
                                                      query.value(0).toBool(),
                                                      query.value(1).toString(),
                                                      query.value(2).toInt(),
                                                      query.value(3).toInt()));
        }

    }
    else
    {
        qDebug() << "Неизвестный запрос";
    }
}
