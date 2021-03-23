#include "mainwindow2.h"
#include "mainmenu.h"
#include "ui_mainwindow2.h"
#include "windows.h"

int MainWindow2::gameSpeed;
MainMenu *MainWindow2::menu;

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow2::MoveSnake1);
    connect(timer, &QTimer::timeout, this, &MainWindow2::MoveSnake2);
    connect(controlTimer, &QTimer::timeout, this, &MainWindow2::GetControls);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::paintEvent(QPaintEvent *event)
{
    if(active)
    {
        QPainter painter(this);

        DrawBounds(&painter);

        for(int i = 0; i < snake1Length; i++)
        {
            DrawSnake1(&painter, snakeX1[i], snakeY1[i]);
        }

        for(int i = 0; i < snake2Length; i++)
        {
            DrawSnake2(&painter, snakeX2[i], snakeY2[i]);
        }

        DrawFood(&painter, foodX, foodY);
    }
}

void MainWindow2::DrawSnake1(QPainter *painter, int x, int y)
{
    QBrush brush;

    brush.setColor(QColor(0,255,0));
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter->setPen(Qt::PenStyle::NoPen);
    painter->setBrush(brush);

    painter->drawRect(x * 10, y * 10 + 60, 10, 10);
}

void MainWindow2::DrawSnake2(QPainter *painter, int x, int y)
{
    QBrush brush;

    brush.setColor(QColor(255,255,0));
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter->setPen(Qt::PenStyle::NoPen);
    painter->setBrush(brush);

    painter->drawRect(x * 10, y * 10 + 60, 10, 10);
}

void MainWindow2::DrawFood(QPainter *painter, int x, int y)
{
    QBrush brush;

    brush.setColor(QColor(255,0,0));
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter->setPen(Qt::PenStyle::NoPen);
    painter->setBrush(brush);

    painter->drawRect(x * 10, y * 10 + 60, 10, 10);
}

void MainWindow2::DrawBounds(QPainter *painter)
{
    QPen pen;

    pen.setColor(QColor(0,0,0));

    painter->setBrush(Qt::BrushStyle::NoBrush);
    painter->setPen(pen);

    painter->drawLine(0,60,600,60);
}

void MainWindow2::GetControls()
{
    //Snake 1
    if(GetAsyncKeyState('A') < 0 && !(GetAsyncKeyState('D') < 0) && !(GetAsyncKeyState('W') < 0) && !(GetAsyncKeyState('S') < 0) && (snakeX1Speed != 1))
    {
        snakeX1Speed = -1;
        snakeY1Speed = 0;
    }
    else if(!(GetAsyncKeyState('A') < 0) && GetAsyncKeyState('D') < 0 && !(GetAsyncKeyState('W') < 0) && !(GetAsyncKeyState('S') < 0) && (snakeX1Speed != -1))
    {
        snakeX1Speed = 1;
        snakeY1Speed = 0;
    }
    else if(!(GetAsyncKeyState('A') < 0) && !(GetAsyncKeyState('D') < 0) && GetAsyncKeyState('W') < 0 && !(GetAsyncKeyState('S') < 0) && (snakeY1Speed != 1))
    {
        snakeY1Speed = -1;
        snakeX1Speed = 0;
    }
    else if(!(GetAsyncKeyState('A') < 0) && !(GetAsyncKeyState('D') < 0) && !(GetAsyncKeyState('W') < 0) && GetAsyncKeyState('S') < 0 && (snakeY1Speed != -1))
    {
        snakeY1Speed = 1;
        snakeX1Speed = 0;
    }


    //Snake 2
    if(GetAsyncKeyState('J') < 0 && !(GetAsyncKeyState('L') < 0) && !(GetAsyncKeyState('I') < 0) && !(GetAsyncKeyState('K') < 0) && (snakeX2Speed != 1))
    {
        snakeX2Speed = -1;
        snakeY2Speed = 0;
    }
    else if(!(GetAsyncKeyState('J') < 0) && GetAsyncKeyState('L') < 0 && !(GetAsyncKeyState('I') < 0) && !(GetAsyncKeyState('K') < 0) && (snakeX2Speed != -1))
    {
        snakeX2Speed = 1;
        snakeY2Speed = 0;
    }
    else if(!(GetAsyncKeyState('J') < 0) && !(GetAsyncKeyState('L') < 0) && GetAsyncKeyState('I') < 0 && !(GetAsyncKeyState('K') < 0) && (snakeY2Speed != 1))
    {
        snakeY2Speed = -1;
        snakeX2Speed = 0;
    }
    else if(!(GetAsyncKeyState('J') < 0) && !(GetAsyncKeyState('L') < 0) && !(GetAsyncKeyState('I') < 0) && GetAsyncKeyState('K') < 0 && (snakeY2Speed != -1))
    {
        snakeY2Speed = 1;
        snakeX2Speed = 0;
    }
}

void MainWindow2::MoveSnake1()
{
    GetControls();

    for(int i = snake1Length - 1; i > 0; i--)
    {
        //Move this segment
        snakeX1[i] = snakeX1[i-1];
        snakeY1[i] = snakeY1[i-1];
    }

    snakeX1[0] += snakeX1Speed;
    snakeY1[0] += snakeY1Speed;

    for(int i = 0; i < snake1Length; i++)
    {
        //Check to see if we have run into ourselves
        for(int j = 0; j < snake1Length; j++)
        {
            if(j != i)
            {
                if(snakeX1[i] == snakeX1[j] && snakeY1[i] == snakeY1[j])
                {
                    Died1();
                    break;
                }
            }
        }
    }

    //Check to make sure the head of the snake is within the bounds of the board
    if(snakeX1[0] < 0 || snakeX1[0] > 59 || snakeY1[0] < 0 || snakeY1[0] > 59)
    {
        Died1();
    }

    //Check to see if we hit the other snake
    for(int i = 1; i < snake2Length; i++)
    {
        if(snakeX1[0] == snakeX2[i] && snakeY1[0] == snakeY2[i])
        {
            Died1();
        }
    }

    //If our head ovelaps the food eat it and make a new food
    if(snakeX1[0] == foodX && snakeY1[0] == foodY)
    {
        snakeX1[snake1Length] = snakeX1[snake1Length - 1] + (-1 * snakeX1Speed);
        snakeY1[snake1Length] = snakeY1[snake1Length - 1] + (-1 * snakeY1Speed);
        snake1Length += 1;
        score1 += 1;
        CreateFood();
    }

    ui->lcd_score1->display(score1);
    this->update();
}

void MainWindow2::MoveSnake2()
{
    GetControls();

    for(int i = snake2Length - 1; i > 0; i--)
    {
        //Move this segment
        snakeX2[i] = snakeX2[i-1];
        snakeY2[i] = snakeY2[i-1];
    }

    snakeX2[0] += snakeX2Speed;
    snakeY2[0] += snakeY2Speed;

    for(int i = 0; i < snake2Length; i++)
    {
        //Check to see if we have run into ourselves
        for(int j = 0; j < snake2Length; j++)
        {
            if(j != i)
            {
                if(snakeX2[i] == snakeX2[j] && snakeY2[i] == snakeY2[j])
                {
                    Died2();
                    break;
                }
            }
        }
    }

    //Check to make sure the head of the snake is within the bounds of the board
    if(snakeX2[0] < 0 || snakeX2[0] > 59 || snakeY2[0] < 0 || snakeY2[0] > 59)
    {
        Died2();
    }

    //Check to see if we hit the other snake
    for(int i = 1; i < snake1Length; i++)
    {
        if(snakeX2[0] == snakeX1[i] && snakeY2[0] == snakeY1[i])
        {
            Died2();
        }
    }

    //If our head ovelaps the food eat it and make a new food
    if(snakeX2[0] == foodX && snakeY2[0] == foodY)
    {
        snakeX2[snake2Length] = snakeX2[snake2Length - 1] + (-1 * snakeX2Speed);
        snakeY2[snake2Length] = snakeY2[snake2Length - 1] + (-1 * snakeY2Speed);
        snake2Length += 1;
        score2 += 1;
        CreateFood();
    }

    ui->lcd_score2->display(score2);
    this->update();
}

void MainWindow2::Reset()
{
    //Reset our length and speed;
    snake1Length = 2;
    snakeX1Speed = 1;
    snakeY1Speed = 0;
    score1 = 0;

    //Clear out the arrays representing the snake's position
    std::fill_n(snakeX1,3600,0);
    std::fill_n(snakeY1,3600,0);

    //Create the first pieces of the snake
    snakeX1[0] = 30;
    snakeY1[0] = 20;
    snakeX1[1] = 29;
    snakeY1[1] = 20;



    //Reset our length and speed;
    snake2Length = 2;
    snakeX2Speed = 1;
    snakeY2Speed = 0;
    score2 = 0;

    //Clear out the arrays representing the snake's position
    std::fill_n(snakeX2,3600,0);
    std::fill_n(snakeY2,3600,0);

    //Create the first pieces of the snake
    snakeX2[0] = 30;
    snakeY2[0] = 40;
    snakeX2[1] = 29;
    snakeY2[1] = 40;



    //Create the first piece of food
    CreateFood();

    //start the event timer
    timer->start(gameSpeed);
    controlTimer->start(5);

    active = true;
}

void MainWindow2::Died1()
{
    if(active)
    {
        active = false;
        timer->stop();
        controlTimer->stop();

        QMessageBox::information(0, QString("Player 2 Wins"), QString("Player 1 has died, so Player 2 wins!!"), QMessageBox::Ok);

        menu->show();
        this->hide();
    }
}

void MainWindow2::Died2()
{
    if(active)
    {
        active = false;
        timer->stop();
        controlTimer->stop();

        QMessageBox::information(0, QString("Player 1 Wins"), QString("Player 2 has died, so Player 1 wins!!"), QMessageBox::Ok);

        menu->show();
        this->hide();
    }
}

//Fix this Christopher--------------------------------------------------------------------------------------------------------------
void MainWindow2::CreateFood()
{
    bool foodValid = false;

    while(!foodValid)
    {
        foodX = QRandomGenerator::global()->bounded(1,59);
        foodY = QRandomGenerator::global()->bounded(1,59);

        foodValid = true;
        for(int i = 0; i < snake1Length; i++)
        {
            if(foodX == snakeX1[i] && foodY == snakeY1[i])
            {
                foodValid = false;
            }
        }
        for(int i = 0; i < snake2Length; i++)
        {
            if(foodX == snakeX2[i] && foodY == snakeY2[i])
            {
                foodValid = false;
            }
        }
    }
}

void MainWindow2::on_btn_exit_clicked()
{
    active = false;
    timer->stop();
    controlTimer->stop();
    menu->show();
    this->hide();
}
