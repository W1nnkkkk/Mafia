#include "rooms.h"
#include "ui_rooms.h"
#include "roomjsoncontroller.h"
#include <thread>

#define ROOM_NAME 1
#define BOOL_DATA 3
#define WHO 2
#define MESSAGE 2
#define COMMAND 3
#define STATE 3
#define FOR_WHO 3
#define REQ_TYPE 0


Rooms::Rooms(QWidget *parent, MainLobby* ptr, QString roomName)
    : QWidget(parent)
    , ui(new Ui::Rooms)
{
    ui->setupUi(this);

    this->mainLobby = ptr;
    this->setWindowTitle(roomName);

    connect(mainLobby, &MainLobby::serverResponseReceived, this, [this](){
        ui->lineEdit->clear();
        qDebug() << mainLobby->dataFromServer[MESSAGE].toString();
        ui->textEdit->append(mainLobby->dataFromServer[MESSAGE].toString());
    });
}

Rooms::~Rooms()
{
    delete ui;
}

void Rooms::on_pushButton_2_clicked()
{
    this->hide();
    mainLobby->show();
    mainLobby->sendToServer(RoomJsonController::formRequest("disconnect", this->windowTitle(), mainLobby->myId));
    this->~Rooms();
}


void Rooms::on_pushButton_clicked()
{
    mainLobby->sendToServer(RoomJsonController::formRequest("message", this->windowTitle(), ui->lineEdit->text()));
}

