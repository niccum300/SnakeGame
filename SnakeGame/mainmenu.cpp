#include "mainmenu.h"
#include "mainwindow.h"
#include "ui_mainmenu.h"

MainWindow *MainMenu::game;

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
    game->gameSpeed = 100;
    game->Reset();
    game->show();
    this->hide();
}

void MainMenu::on_btn_medium_clicked()
{
    game->gameSpeed = 50;
    game->Reset();
    game->show();
    this->hide();
}

void MainMenu::on_btn_hard_clicked()
{
    game->gameSpeed = 25;
    game->Reset();
    game->show();
    this->hide();
}
