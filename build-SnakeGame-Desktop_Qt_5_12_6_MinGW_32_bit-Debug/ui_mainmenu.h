/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QPushButton *btn_easy;
    QPushButton *btn_medium;
    QPushButton *btn_hard;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btn_quit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(250, 360);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        MainMenu->setMinimumSize(QSize(250, 360));
        MainMenu->setMaximumSize(QSize(250, 360));
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_easy = new QPushButton(centralwidget);
        btn_easy->setObjectName(QString::fromUtf8("btn_easy"));
        btn_easy->setGeometry(QRect(10, 70, 231, 41));
        QFont font;
        font.setPointSize(11);
        btn_easy->setFont(font);
        btn_medium = new QPushButton(centralwidget);
        btn_medium->setObjectName(QString::fromUtf8("btn_medium"));
        btn_medium->setGeometry(QRect(10, 120, 231, 41));
        btn_medium->setFont(font);
        btn_hard = new QPushButton(centralwidget);
        btn_hard->setObjectName(QString::fromUtf8("btn_hard"));
        btn_hard->setGeometry(QRect(10, 170, 231, 41));
        btn_hard->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 211, 41));
        QFont font1;
        font1.setPointSize(24);
        label->setFont(font1);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 220, 191, 51));
        label_2->setAlignment(Qt::AlignCenter);
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName(QString::fromUtf8("btn_quit"));
        btn_quit->setGeometry(QRect(80, 280, 91, 25));
        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 250, 25));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "SnakeGame", nullptr));
        btn_easy->setText(QApplication::translate("MainMenu", "Slug (Easy)", nullptr));
        btn_medium->setText(QApplication::translate("MainMenu", "Worm (Medium)", nullptr));
        btn_hard->setText(QApplication::translate("MainMenu", "Python (Hard)", nullptr));
        label->setText(QApplication::translate("MainMenu", "SnakeGame", nullptr));
        label_2->setText(QApplication::translate("MainMenu", "<html><head/><body><p>Brayton Niccum<br>Michael Swango<br>Christopher Feguson</p></body></html>", nullptr));
        btn_quit->setText(QApplication::translate("MainMenu", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
