#include "mainwindow.h"
#include "mainmenu.h"
#include "ui_mainwindow.h"
#include "windows.h"

int MainWindow::gameSpeed;
MainMenu *MainWindow::menu;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::MoveSnake);
    connect(timer, &QTimer::timeout, this, &MainWindow::GetControls);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetSounds(std::string mode)
{
    eat.setSource(QUrl::fromLocalFile(":/eat.wav"));
    eat.setLoopCount(1);

    if(mode == "slug")
    {
        music.setSource(QUrl::fromLocalFile(":/fluidvolt-The_Gusts_of_Aeolus.wav"));
        music.setLoopCount(QSoundEffect::Infinite);
        music.setVolume(0.25f);
    }
    else if(mode == "worm")
    {
        music.setSource(QUrl::fromLocalFile(":/Necrophageon-Neon_Starlight.wav"));
        music.setLoopCount(QSoundEffect::Infinite);
        music.setVolume(0.25f);
    }
    else if(mode == "python")
    {
        music.setSource(QUrl::fromLocalFile(":/Kulor-SpaceDolphinsSpaceCave.wav"));
        music.setLoopCount(QSoundEffect::Infinite);
        music.setVolume(0.25f);
    }
}

void MainWindow::SetPlayerName(QString p1)
{
    if (p1 == "")
    {
        p1 = "Player 1";
    }

    ui->player_label->setText(p1);

    player_1 = p1;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(active)
    {
        QPainter painter(this);

        DrawBounds(&painter);

        for(int i = 0; i < snakeLength; i++)
        {
            DrawSnake(&painter, snakeX[i], snakeY[i]);
        }

        DrawFood(&painter, foodX, foodY);
    }
}

void MainWindow::DrawSnake(QPainter *painter, int x, int y)
{
    QBrush brush;

    brush.setColor(QColor(0,255,0));
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter->setPen(Qt::PenStyle::NoPen);
    painter->setBrush(brush);

    painter->drawRect(x * 10, y * 10 + 60, 10, 10);
}

void MainWindow::DrawFood(QPainter *painter, int x, int y)
{
    QBrush brush;

    brush.setColor(QColor(255,0,0));
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    painter->setPen(Qt::PenStyle::NoPen);
    painter->setBrush(brush);

    painter->drawRect(x * 10, y * 10 + 60, 10, 10);
}

void MainWindow::DrawBounds(QPainter *painter)
{
    QPen pen;

    pen.setColor(QColor(0,0,0));

    painter->setBrush(Qt::BrushStyle::NoBrush);
    painter->setPen(pen);

    painter->drawLine(0,60,600,60);
}

void MainWindow::GetControls()
{
    if(GetAsyncKeyState('A') < 0 && !(GetAsyncKeyState('D') < 0) && !(GetAsyncKeyState('W') < 0) && !(GetAsyncKeyState('S') < 0) && (snakeXSpeed != 1))
    {
        snakeXSpeed = -1;
        snakeYSpeed = 0;
    }
    else if(!(GetAsyncKeyState('A') < 0) && GetAsyncKeyState('D') < 0 && !(GetAsyncKeyState('W') < 0) && !(GetAsyncKeyState('S') < 0) && (snakeXSpeed != -1))
    {
        snakeXSpeed = 1;
        snakeYSpeed = 0;
    }
    else if(!(GetAsyncKeyState('A') < 0) && !(GetAsyncKeyState('D') < 0) && GetAsyncKeyState('W') < 0 && !(GetAsyncKeyState('S') < 0) && (snakeYSpeed != 1))
    {
        snakeYSpeed = -1;
        snakeXSpeed = 0;
    }
    else if(!(GetAsyncKeyState('A') < 0) && !(GetAsyncKeyState('D') < 0) && !(GetAsyncKeyState('W') < 0) && GetAsyncKeyState('S') < 0 && (snakeYSpeed != -1))
    {
        snakeYSpeed = 1;
        snakeXSpeed = 0;
    }
}

void MainWindow::MoveSnake()
{
    GetControls();

    for(int i = snakeLength - 1; i > 0; i--)
    {
        //Move this segment
        snakeX[i] = snakeX[i-1];
        snakeY[i] = snakeY[i-1];
    }

    snakeX[0] += snakeXSpeed;
    snakeY[0] += snakeYSpeed;

    for(int i = 0; i < snakeLength; i++)
    {
        //Check to see if we have run into ourselves
        for(int j = 0; j < snakeLength; j++)
        {
            if(j != i)
            {
                if(snakeX[i] == snakeX[j] && snakeY[i] == snakeY[j])
                {
                    Died();
                    break;
                }
            }
        }
    }

    //Check to make sure the head of the snake is within the bounds of the board
    if(snakeX[0] < 0 || snakeX[0] > 59 || snakeY[0] < 0 || snakeY[0] > 59)
    {
        Died();
    }

    //If our head ovelaps the food eat it and make a new food
    if(snakeX[0] == foodX && snakeY[0] == foodY)
    {
        eat.play();
        snakeX[snakeLength] = snakeX[snakeLength - 1] + (-1 * snakeXSpeed);
        snakeY[snakeLength] = snakeY[snakeLength - 1] + (-1 * snakeYSpeed);
        snakeLength += 1;
        score += 1;
        CreateFood();
    }

    ui->lcd_score->display(score);
    this->update();
}

void MainWindow::Reset()
{
    //Reset our length and speed;
    snakeLength = 2;
    snakeXSpeed = 1;
    snakeYSpeed = 0;
    score = 0;

    //Clear out the arrays representing the snake's position
    std::fill_n(snakeX,3600,0);
    std::fill_n(snakeY,3600,0);

    //Create the first pieces of the snake
    snakeX[0] = 30;
    snakeY[0] = 30;
    snakeX[1] = 29;
    snakeY[1] = 30;

    //Create the first piece of food
    CreateFood();

    //start the event timer
    timer->start(gameSpeed);
    controlTimer->start(5);

    music.play();

    active = true;
}

void MainWindow::Died()
{
    if(active)
    {
        active = false;
        timer->stop();
        controlTimer->stop();

        QMessageBox::information(0, QString("You Lose"), QString("You Died!!!"), QMessageBox::Ok);

        music.stop();
        menu->show();
        menu->menu.play();
        this->hide();
    }
}

//Fix this Christopher--------------------------------------------------------------------------------------------------------------
void MainWindow::CreateFood()
{
    bool foodValid = false;

    while(!foodValid)
    {
        foodX = QRandomGenerator::global()->bounded(1,59);
        foodY = QRandomGenerator::global()->bounded(1,59);

        foodValid = true;
        for(int i = 0; i < snakeLength; i++)
        {
            if(foodX == snakeX[i] && foodY == snakeY[i])
            {
                foodValid = false;
            }
        }
    }
}

void MainWindow::on_btn_exit_clicked()
{
    active = false;
    timer->stop();
    controlTimer->stop();
    music.stop();
    menu->show();
    menu->menu.play();
    this->hide();
}
