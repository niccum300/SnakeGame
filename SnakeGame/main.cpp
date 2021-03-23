#include "mainwindow.h"
#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    MainWindow w2;
    MainWindow2 w3;


    w.game = &w2;
    w.game2 = &w3;

    w.game->menu = &w;
    w.game2->menu = &w;
    return a.exec();
}
