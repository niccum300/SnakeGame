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
    ui->player_2_label_2->hide();
    ui->txt_box_p2->hide();
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

void MainMenu::on_rad_multiplayer_clicked()
{
    if (ui->rad_multiplayer->isChecked())
    {
        ui->txt_box_p2->show();
        ui->player_2_label_2->show();

    }else if(!ui->rad_multiplayer->isChecked())
    {
        ui->txt_box_p2->hide();
        ui->player_2_label_2->hide();
    }
}
