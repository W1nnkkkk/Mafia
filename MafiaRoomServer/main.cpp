#include <QCoreApplication>
#include "roomserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RoomServer server;

    return a.exec();
}
