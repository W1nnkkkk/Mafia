#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#define REQUEST 0
#define LOGIN 1
#define PASSWORD 2

#define REGISTER_TYPE 1
#define LOGIN_TYPE 2

/*
 client:
    {
        "request" : "register", "login"
        "data" :
            [
                "login" : ui->login,
                "pass" : ui->pass
            ]
    }
 server:
    {
        "requestType" : "register", "login",
        "completeRequest" : "true", "false",
        "accountData" :
            [
                "name" : "email",
                "gamesCount" : "gamesCount",
                "points" : "accountPoints"
            ]
    }
*/

class JsonController
{
public:
    JsonController();

    static QVector<QString> getRequestFromClient(QJsonDocument data);
    static QJsonDocument formResponse(int reqType, bool compReq, QString email, int gamesCount, int points);
};

#endif // JSONCONTROLLER_H
