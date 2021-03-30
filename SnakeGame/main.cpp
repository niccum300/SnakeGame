#include "mainwindow.h"
#include "mainmenu.h"
#include "help.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    MainWindow w2;
    MainWindow2 w3;
    help helpMenu;


    w.game = &w2;
    w.game2 = &w3;
    w.helpMenu = &helpMenu;

    w.game->menu = &w;
    w.game2->menu = &w;
    return a.exec();
}
