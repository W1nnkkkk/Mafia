/********************************************************************************
** Form generated from reading UI file 'rooms.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMS_H
#define UI_ROOMS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rooms
{
public:
    QFormLayout *formLayout;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *Rooms)
    {
        if (Rooms->objectName().isEmpty())
            Rooms->setObjectName("Rooms");
        Rooms->resize(408, 278);
        formLayout = new QFormLayout(Rooms);
        formLayout->setObjectName("formLayout");
        textEdit = new QTextEdit(Rooms);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, textEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Rooms);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Rooms);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(Rooms);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(Rooms);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(Rooms);
        pushButton->setObjectName("pushButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/arrow.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout);


        retranslateUi(Rooms);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(Rooms);
    } // setupUi

    void retranslateUi(QWidget *Rooms)
    {
        Rooms->setWindowTitle(QCoreApplication::translate("Rooms", "Form", nullptr));
        label->setText(QCoreApplication::translate("Rooms", "\320\222\320\260\321\210\320\260 \321\200\320\276\320\273\321\214:", nullptr));
        label_2->setText(QCoreApplication::translate("Rooms", "RoleText", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Rooms", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rooms: public Ui_Rooms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMS_H
