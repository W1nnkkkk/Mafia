#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginPage;
}
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

public slots:
    void onReadyRead();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void sendToServer(QJsonDocument doc);
    Ui::LoginPage *ui;
    QVector<QVariant> accData;
    QByteArray dataToServer;
    QTcpSocket* socket;
};


#endif // LOGINPAGE_H
