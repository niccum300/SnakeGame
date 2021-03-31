#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_exit_btn_clicked()
{
    this->close();
}
