#ifndef MAINLOBBY_H
#define MAINLOBBY_H

#include <QWidget>
#include <QToolBar>
#include <QTcpSocket>

class Rooms;

namespace Ui {
class MainLobby;
}

class MainLobby : public QWidget
{
    Q_OBJECT

public:
    MainLobby(QWidget *parent = nullptr, QString email = "", int games_count = 0, int points = 0);
    ~MainLobby();

    friend Rooms;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void onReadyRead();

    void on_pushButton_4_clicked();

signals:
    void serverResponseReceived();

private:
    Ui::MainLobby *ui;
    QTcpSocket* socket;
    QByteArray data;
    QString typeReq;
    int myId;
    QVector<QVariant> dataFromServer;
    void sendToServer(QJsonDocument doc);
    void execResponse();
};

#endif // MAINLOBBY_H
