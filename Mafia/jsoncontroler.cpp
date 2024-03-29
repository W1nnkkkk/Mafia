#include "jsoncontroler.h"
#include <QDebug>
#include <QMessageBox>

JsonController::JsonController() {}

QVector<QVariant> JsonController::getRequestFromServer(QJsonDocument data)
{
    if (data["completeRequest"].toBool())
    {
        QVector<QVariant> tmp { QVariant(data["accountData"][EMAIL]),
                                QVariant(data["accountData"][GAMES_COUNT]),
                                QVariant(data["accountData"][POINTS])};
        return tmp;
    }
    else
    {
        QVector<QVariant> tmp { QVariant(0) };
        switch (data["requestType"].toInt()) {
            case REGISTER_TYPE:
                QMessageBox::warning(nullptr, "Warning", "Такой пользователь уже существует");
                return tmp;
                break;
            case LOGIN_TYPE:
                QMessageBox::warning(nullptr, "Warning", "Такого пользователя не существует");
                return tmp;
                break;
            default:
                qDebug() << "Непредсказуемый ответ";
                return tmp;
        }
    }
}

QJsonDocument JsonController::formResponse(QString req, QString log, QString pass)
{
    QJsonObject jsonObject;
    jsonObject["request"] = req;

    QJsonArray loginPass;

    QJsonValue login = log;
    QJsonValue password = pass;
    loginPass.append(log);
    loginPass.append(password);

    jsonObject["data"] = loginPass;

    QJsonDocument jsonDocument(jsonObject);

    return jsonDocument;
}
