#include "loginpage.h"
#include "ui_loginpage.h"
#include "mainlobby.h"
#include "jsoncontroler.h"
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>

QRegularExpression regExp = QRegularExpression("^[-a-z0-9~!$%^&*_=+}{\'?]+"
                                               "(\\.[-a-z0-9~!$%^&*_=+}{\'?]+)*@([a-z0-9_][-a-z0-9_]*(\\.[a-z0-9_]+)*(\\."
                                               "(aero|arpa|biz|com|coop|edu|gov|info"
                                               "|int|jobs|mil|mobi|museum|name|net|org|pro|travel|museum|name|net|org|pro)"
                                               "(:[0-9]{1,5})?|([0-9]{1,3}\\.){3}[0-9]{1,3}))$");

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->login->setValidator(validator);

    socket = new QTcpSocket();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

    socket->connectToHost("127.0.0.1", 2323);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::onReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        QJsonDocument message;
        in >> message;
        accData = JsonController::getRequestFromServer(message);
        if (accData.size() == 3){
            MainLobby* mainLobby = new MainLobby(nullptr, accData[EMAIL].toString(),
                                                 accData[GAMES_COUNT].toInt(),
                                                 accData[POINTS].toInt());
            this->hide();
            mainLobby->show();
            this->~LoginPage();
        }
    }
    else
    {
        qDebug() << "Error while reading data";
    }
}

void LoginPage::on_pushButton_clicked()
{
    if (regExp.match(ui->login->text()).hasMatch() && (ui->password->text() != ""))
    {
        sendToServer(JsonController::formResponse("login", ui->login->text(), ui->password->text()));

    }
    else
    {
        QMessageBox::information(this, "Неккоректные данные", "Введите верные данные для поля login или password");
    }
}


void LoginPage::on_pushButton_2_clicked()
{
    if (regExp.match(ui->login->text()).hasMatch() && (ui->password->text() != ""))
    {
        sendToServer(JsonController::formResponse("register", ui->login->text(), ui->password->text()));
    }
    else
    {
        QMessageBox::information(this, "Неккоректные данные", "Введите верные данные для поля login или password");
    }
}

void LoginPage::sendToServer(QJsonDocument doc)
{
    dataToServer.clear();
    QDataStream out(&dataToServer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << doc;
    socket->write(dataToServer);
}

