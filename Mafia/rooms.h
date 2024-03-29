#ifndef ROOMS_H
#define ROOMS_H

#include <QWidget>
#include "mainlobby.h"

namespace Ui {
class Rooms;
}

class Rooms : public QWidget
{
    Q_OBJECT

public:
    explicit Rooms(QWidget *parent = nullptr, MainLobby* ptr = nullptr, QString roomName = "");
    ~Rooms();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Rooms *ui;
    MainLobby* mainLobby;
};

#endif // ROOMS_H
