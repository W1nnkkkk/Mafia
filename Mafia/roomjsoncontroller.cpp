#include "roomjsoncontroller.h"
#include <QDebug>
#include <QMessageBox>

RoomJsonController::RoomJsonController() {}

QVector<QVariant> RoomJsonController::getResponseFromServer(QJsonDocument data)
{
    QString type = data["responseType"].toString();
    if (type == "create")
    {
        QVector<QVariant> tmp { QVariant(type),
                                QVariant(data["message"])};
        return tmp;
    }
    else if (type == "connection")
    {
        QVector<QVariant> tmp { QVariant(type),
                              QVariant(data["roomName"]),
                              QVariant(data["who"]),
                              QVariant(data["responseBool"])};
        return tmp;
    }
    else if(type == "message")
    {
        QVector<QVariant> tmp { QVariant(type),
                              QVariant(data["roomName"]),
                              QVariant(data["message"]) };
        return tmp;
    }
}

QJsonDocument RoomJsonController::formRequest(QString req, QString roomName,QString message)
{
    if (req == "message")
    {
        QJsonObject jsonObject;
        jsonObject["reqType"] = req;
        jsonObject["roomName"] = roomName;
        jsonObject["message"] = message;
        QJsonDocument doc(jsonObject);
        return doc;
    }
    else if (req == "create")
    {
        QJsonObject jsonObject;
        jsonObject["reqType"] = req;
        jsonObject["roomName"] = roomName;
        QJsonDocument doc(jsonObject);
        return doc;
    }
    else if(req == "connection")
    {
        QJsonObject jsonObject;
        jsonObject["reqType"] = req;
        jsonObject["roomName"] = roomName;
        QJsonDocument doc(jsonObject);
        return doc;
    }
}

QJsonDocument RoomJsonController::formRequest(QString req, QString roomName, int who)
{
    QJsonObject jsonObject;
    jsonObject["reqType"] = req;
    jsonObject["roomName"] = roomName;
    jsonObject["who"] = who;
    QJsonDocument doc(jsonObject);
    return doc;
}
QJsonDocument RoomJsonController::formRequest(QString req, QString roomName, int who, int forWhom)
{
    QJsonDocument doc;
    return doc;
}


