#include <QCoreApplication>
#include "databaseserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataBaseServer server;

    return a.exec();
}
