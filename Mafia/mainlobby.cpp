#include "mainlobby.h"
#include "ui_mainlobby.h"
#include "roomjsoncontroller.h"
#include <QMessageBox>
#include "rooms.h"

#define ROOM_NAME 1
#define BOOL_DATA 3
#define WHO 2
#define MESSAGE 2
#define COMMAND 3
#define STATE 3
#define FOR_WHO 3
#define REQ_TYPE 0

MainLobby::MainLobby(QWidget *parent, QString email, int gamesCount, int points)
    : QWidget(parent)
    , ui(new Ui::MainLobby)
{
    ui->setupUi(this);
    ui->nameLabel->setText(email.chopped(email.length() - 6));
    ui->pointsLabel->setText(QVariant(points).toString());
    ui->gamesCountLabel->setText(QVariant(gamesCount).toString());

    socket = new QTcpSocket();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

    socket->connectToHost("127.0.0.1", 2424);
}

MainLobby::~MainLobby()
{
    delete ui;
}

void MainLobby::on_pushButton_clicked()
{
    ui->pushButton_4->setText("Подключиться");

    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);

    typeReq = "connection";
}


void MainLobby::on_pushButton_2_clicked()
{
    ui->pushButton_4->setText("Создать");

    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);

    typeReq = "create";
}


void MainLobby::on_pushButton_3_clicked()
{
    exit(0); //TODO
}

void MainLobby::onReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    qDebug() << "ready read";
    if (in.status() == QDataStream::Ok)
    {
        QJsonDocument message;
        in >> message;
        qDebug() << message;
        dataFromServer = RoomJsonController::getResponseFromServer(message);
        emit serverResponseReceived();
        qDebug() << dataFromServer[0].toString();
        if (dataFromServer[REQ_TYPE].toString() == "create")
        {
            QMessageBox::information(nullptr, "info", dataFromServer[ROOM_NAME].toString());
        }
        else
        {
            execResponse();
        }

    }
    else
    {
        qDebug() << "Error while reading data";
    }
}

void MainLobby::sendToServer(QJsonDocument doc)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << doc;
    socket->write(data);
}

void MainLobby::execResponse()
{
    if (dataFromServer[REQ_TYPE].toString() == "connection")
    {
        if (dataFromServer[BOOL_DATA].toBool())
        {
            Rooms* room = new Rooms(nullptr, this, dataFromServer[ROOM_NAME].toString());
            this->hide();
            room->show();
        }
    }
    else
    {
        qDebug() << "Nothing...";
    }
}

void MainLobby::on_pushButton_4_clicked()
{
    if (typeReq != "")
    {
        qDebug() << RoomJsonController::formRequest(typeReq, ui->lineEdit->text(), "");
        sendToServer(RoomJsonController::formRequest(typeReq, ui->lineEdit->text(), ""));
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
        ui->lineEdit->clear();
    }
    else
    {
        QMessageBox::warning(this, "Выберите тип", "Пожалуйста выберите тип запроса к комнате");
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
        ui->lineEdit->clear();
    }
}

