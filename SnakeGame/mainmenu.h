#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "mainwindow.h"
#include "mainwindow2.h"
#include "help.h"
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
    static MainWindow2 *game2;
    help *helpMenu;

private slots:

    void on_btn_quit_clicked();

    void on_btn_easy_clicked();

    void on_btn_medium_clicked();

    void on_btn_hard_clicked();


    void on_rad_multiplayer_clicked();

    void on_help_btn_clicked();

private:
    Ui::MainMenu *ui;

    void set_players();
    void reset_menu();
};

#endif // MAINMENU_H
