#ifndef ROOM_H
#define ROOM_H

#include <QTcpSocket>
#include <QString>

struct Room
{
    QMap<int, QTcpSocket*> clients_num;
    QMap<int, QString> clients_state;
    QMap<int, QString> clients_role;
    int playersCount = 0;
    int playersNO;
};

#endif // ROOM_H
