#include "jsoncontroller.h"

JsonController::JsonController() {}

QJsonDocument JsonController::formResponseToClient(QString type,
                                                   int myName,
                                                   QMap<QString, Room> rooms,
                                                   QString message)
{
    if (type == "connect")
    {

    }
    else if (type == "updateTable")
    {

    }
    else if (type == "message")
    {
        QJsonObject jsonObj;
        jsonObj["responseType"] = type;
        jsonObj["fromWho"] = myName;
        jsonObj["message"] = message;

        QJsonDocument doc(jsonObj);
        return doc;
    }
}

QJsonDocument JsonController::formCreateResponse(QString type, QString message)
{
    QJsonObject jsonObject;
    jsonObject["responseType"] = type;
    jsonObject["message"] = message;
    QJsonDocument doc(jsonObject);
    return doc;
}

QJsonDocument JsonController::formConnectResponse(QString type, QString roomName, int myId)
{
    QJsonObject jsonObject;
    jsonObject["responseType"] = type;
    jsonObject["roomName"] = roomName;
    jsonObject["who"] = myId;
    jsonObject["responseBool"] = true;
    QJsonDocument doc(jsonObject);
    return doc;
}

QVector<QVariant> JsonController::getRequestFromClient(QJsonDocument data)
{
    QString type = data["reqType"].toString();
    if (type == "giveAChoise")
    {
        QVector<QVariant> tmp { QVariant(type),
                                QVariant(data["roomName"]),
                                QVariant(data["who"]),
                                QVariant(data["forWho"])};
        return tmp;
    }
    else if (type == "connection")
    {
        QVector<QVariant> tmp { QVariant(type),
                                QVariant(data["roomName"])};
        return tmp;
    }
    else if (type == "create")
    {
        QVector<QVariant> tmp { QVariant(type),
                                QVariant(data["roomName"]) };
        return tmp;
    }
    else if (type == "changeState")
    {
        QVector<QVariant> tmp{  QVariant(type),
                                QVariant(data["roomName"]),
                                QVariant(data["who"]),
                                QVariant(data["state"])};
        return tmp;
    }
    else if (type == "message")
    {
        QVector<QVariant> tmp { QVariant(type),
                              QVariant(data["roomName"]),
                              QVariant(data["message"])};
        return tmp;
    }
    else if(type == "disconnect")
    {
        QVector<QVariant> tmp { QVariant(type),
                              QVariant(data["roomName"]),
                              QVariant(data["who"])};
        return tmp;
    }
}
