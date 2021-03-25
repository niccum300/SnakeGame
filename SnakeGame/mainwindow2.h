#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>

class MainMenu;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow2; }
QT_END_NAMESPACE

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

    static MainMenu *menu;

    //Handles all painting
    virtual void paintEvent(QPaintEvent *event);

    bool active = false;
    int foodX = 0;
    int foodY = 0;


    int snake1Length = 0;
    int snakeX1Speed = 0;
    int snakeY1Speed = 0;
    int score1 = 0;

    int snake2Length = 0;
    int snakeX2Speed = 0;
    int snakeY2Speed = 0;
    int score2 = 0;

    //Initalize an array of zeros
    int snakeX1[3600] = {0};
    int snakeY1[3600] = {0};

    //Initalize an array of zeros
    int snakeX2[3600] = {0};
    int snakeY2[3600] = {0};

    static int gameSpeed;

    void Reset();
    void MoveSnake1();
    void MoveSnake2();
    void DrawSnake1(QPainter *painter, int x, int y);
    void DrawSnake2(QPainter *painter, int x, int y);
    void DrawFood(QPainter *painter, int x, int y);
    void DrawBounds(QPainter *painter);
    void Died1();
    void Died2();
    void CreateFood();
    void GetControls();
    void SetPlayerNames(QString p1, QString p2);

    QTimer *timer = new QTimer(this);
    QTimer *controlTimer = new QTimer(this);

private slots:
    void on_btn_exit_clicked();

private:
    Ui::MainWindow2 *ui;

    QString player_1;
    QString player_2;
};
#endif // MAINWINDOW_H
