#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#define EMAIL 0
#define GAMES_COUNT 1
#define POINTS 2

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

    static QVector<QVariant> getRequestFromServer(QJsonDocument data);
    static QJsonDocument formResponse(QString req, QString login, QString pass);
};

#endif // JSONCONTROLLER_H
