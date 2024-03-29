#ifndef ROOMSERVER_H
#define ROOMSERVER_H

#include "Room.h"
#include <QTcpServer>

class RoomServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit RoomServer(QObject *parent = nullptr);

    QMap<QString, Room> chatRooms;
public slots:
    void onReadyRead();

    // QTcpServer interface
protected:
    virtual void incomingConnection(qintptr handle);

private:
    QByteArray data;
    QString roomName;
    QTcpSocket* thisPlayer;
    QStringList roles { "Мирный", "Мафия", "Доктор", "Коммисар" };
    void sendToClient(QJsonDocument str);
    void execRequest(QVector<QVariant> commands);
};

#endif // ROOMSERVER_H
