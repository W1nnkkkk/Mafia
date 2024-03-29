#ifndef ROOMJSONCONTROLLER_H
#define ROOMJSONCONTROLLER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

/*
 client:
    {
        "reqType" : "addMessage", "giveAChoise", "connection", "createRoom", "changePlayerState", "takePlayers"
        "message" : message text
        "giveAChoise" :
            [
                "roomName" : nameRoom,
                "who" : intNum,
                "forWhom" :  intNum
            ]
        "connection" :
            [
                "roomName" : nameRoom,
                "roomPassword" : roomPassword
            ]
        "createRoom"
            [
                "roomName" : nameRoom,
                "roomPassword" : roomPassword
            ]
        "changePlayerState" :
            [
                "roomName" : nameRoom,
                "who" : intNum,
                "state" : stringState
            ]
        "takePlayers" - ?
    }
 server:
    {
        "respType" : "connection/createState", "updateTable", "giveMessageAll"
        "connectCreateState" : true/false
        "updateTable"
            [
                "yourNum" : your socket num
                "aliveNums" : socket nums arr
                "deathNums" : socket nums arr
            ]
        "message" : message text
    }
*/


class RoomJsonController
{
public:
    RoomJsonController();

    static QVector<QVariant> getResponseFromServer(QJsonDocument data);
    static QJsonDocument formRequest(QString req, QString roomName, QString message);
    static QJsonDocument formRequest(QString req, QString roomName, int who);
    static QJsonDocument formRequest(QString req, QString roomName, int who, int forWhom);
};

#endif // ROOMJSONCONTROLLER_H
