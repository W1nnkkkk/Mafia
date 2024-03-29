/********************************************************************************
** Form generated from reading UI file 'mainlobby.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINLOBBY_H
#define UI_MAINLOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainLobby
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *gameTab;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_4;
    QWidget *accountTab;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *gamesCountLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *pointsLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;

    void setupUi(QWidget *MainLobby)
    {
        if (MainLobby->objectName().isEmpty())
            MainLobby->setObjectName("MainLobby");
        MainLobby->resize(436, 384);
        verticalLayout = new QVBoxLayout(MainLobby);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(MainLobby);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::West);
        gameTab = new QWidget();
        gameTab->setObjectName("gameTab");
        verticalLayout_2 = new QVBoxLayout(gameTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stackedWidget = new QStackedWidget(gameTab);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer = new QSpacerItem(20, 115, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");

        verticalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_4->addWidget(pushButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 114, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_5->addWidget(lineEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_5->addWidget(pushButton_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);

        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/gamePad.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(gameTab, icon, QString());
        accountTab = new QWidget();
        accountTab->setObjectName("accountTab");
        verticalLayout_3 = new QVBoxLayout(accountTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(accountTab);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        nameLabel = new QLabel(accountTab);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout_2->addWidget(nameLabel);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(accountTab);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        gamesCountLabel = new QLabel(accountTab);
        gamesCountLabel->setObjectName("gamesCountLabel");

        horizontalLayout_3->addWidget(gamesCountLabel);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(accountTab);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        pointsLabel = new QLabel(accountTab);
        pointsLabel->setObjectName("pointsLabel");

        horizontalLayout_4->addWidget(pointsLabel);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout_4);


        verticalLayout_3->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(accountTab);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/accountIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(accountTab, icon1, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainLobby);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainLobby);
    } // setupUi

    void retranslateUi(QWidget *MainLobby)
    {
        MainLobby->setWindowTitle(QCoreApplication::translate("MainLobby", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MainLobby", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainLobby", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainLobby", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(gameTab), QString());
        label->setText(QCoreApplication::translate("MainLobby", "\320\230\320\274\321\217:", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainLobby", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainLobby", "\320\232\320\276\320\273-\320\262\320\276 \320\270\320\263\321\200:", nullptr));
        gamesCountLabel->setText(QCoreApplication::translate("MainLobby", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainLobby", "\320\232\320\276\320\273-\320\262\320\276 \320\276\321\207\320\272\320\276\320\262:", nullptr));
        pointsLabel->setText(QCoreApplication::translate("MainLobby", "TextLabel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainLobby", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(accountTab), QString());
    } // retranslateUi

};

namespace Ui {
    class MainLobby: public Ui_MainLobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINLOBBY_H
