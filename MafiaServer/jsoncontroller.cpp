#include "jsoncontroller.h"

JsonController::JsonController() {}

QVector<QString> JsonController::getRequestFromClient(QJsonDocument data)
{
    QVector<QString> reqLoginPass;
    QJsonValue tmp;
    tmp = data["request"];
    reqLoginPass.push_back(tmp.toString());
    tmp = data["data"][0];
    reqLoginPass.push_back(tmp.toString());
    tmp = data["data"][1];
    reqLoginPass.push_back(tmp.toString());
    return reqLoginPass;
}

QJsonDocument JsonController::formResponse(int reqType, bool compReq, QString email, int gamesCount, int points)
{
    if (compReq)
    {
        QJsonObject jsonObject;
        jsonObject["requestType"] = reqType;
        jsonObject["completeRequest"] = compReq;

        QJsonArray accountData;

        QJsonValue nameAcc = email;
        QJsonValue gameCount = gamesCount;
        QJsonValue accPoints = points;
        accountData.append(nameAcc);
        accountData.append(gameCount);
        accountData.append(accPoints);

        jsonObject["accountData"] = accountData;

        QJsonDocument jsonDocument(jsonObject);
        return jsonDocument;
    }
    else
    {
        QJsonObject jsonObject;
        jsonObject["completeRequest"] = compReq;
        jsonObject["requestType"] = reqType;
        QJsonDocument jsonDocument(jsonObject);
        return jsonDocument;
    }
}
