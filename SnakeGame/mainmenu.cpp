#include "mainmenu.h"
#include "mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainmenu.h"

MainWindow *MainMenu::game;
MainWindow2 *MainMenu::game2;

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_btn_quit_clicked()
{
    QCoreApplication::quit();
}

void MainMenu::on_btn_easy_clicked()
{
    bool multiplayer = ui->rad_multiplayer->isChecked();
    if(multiplayer)
    {
        game2->gameSpeed = 100;
        game2->Reset();
        game2->show();
    }
    else
    {
        game->gameSpeed = 100;
        game->Reset();
        game->show();
    }

    this->hide();
}

void MainMenu::on_btn_medium_clicked()
{
    bool multiplayer = ui->rad_multiplayer->isChecked();
    if(multiplayer)
    {
        game2->gameSpeed = 50;
        game2->Reset();
        game2->show();
    }
    else
    {
        game->gameSpeed = 50;
        game->Reset();
        game->show();
    }

    this->hide();
}

void MainMenu::on_btn_hard_clicked()
{
    bool multiplayer = ui->rad_multiplayer->isChecked();
    if(multiplayer)
    {
        game2->gameSpeed = 25;
        game2->Reset();
        game2->show();
    }
    else
    {
        game->gameSpeed = 25;
        game->Reset();
        game->show();
    }

    this->hide();
}
