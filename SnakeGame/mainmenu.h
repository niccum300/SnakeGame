#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    static MainWindow *game;

private slots:

    void on_btn_quit_clicked();

    void on_btn_easy_clicked();

    void on_btn_medium_clicked();

    void on_btn_hard_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
