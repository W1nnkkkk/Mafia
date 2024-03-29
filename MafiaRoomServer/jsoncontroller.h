#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "Room.h"

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
        "disconnect" :
            {
                "roomName" : nameRoom,
                "who" : intNum
            }
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

class JsonController
{
public:
    JsonController();

    static QJsonDocument formResponseToClient(QString type,
                                              int myName,
                                              QMap<QString, Room> rooms,
                                              QString Message);
    static QJsonDocument formCreateResponse(QString type, QString message);
    static QJsonDocument formConnectResponse(QString type, QString roomName, int myId);

    static QVector<QVariant> getRequestFromClient(QJsonDocument data);
};

#endif // JSONCONTROLLER_H
