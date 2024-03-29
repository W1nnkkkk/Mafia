#ifndef DATABASESERVER_H
#define DATABASESERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>


class DataBaseServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit DataBaseServer(QObject *parent = nullptr);

public slots:
    void onReadyRead();
    void onDisconnected();

    // QTcpServer interface
protected:
    virtual void incomingConnection(qintptr handle);

private:
    QSqlDatabase usersDb;
    QByteArray dataByteArray;
    void sendToClient(QJsonDocument jsonDoc);
    void executeRequest(QVector<QString> reqLoginPass);
};

#endif // DATABASESERVER_H
