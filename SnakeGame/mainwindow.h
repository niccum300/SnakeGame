#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>

class MainMenu;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static MainMenu *menu;

    //Handles all painting
    virtual void paintEvent(QPaintEvent *event);

    bool active = false;
    int foodX = 0;
    int foodY = 0;
    int snakeLength = 0;
    int snakeXSpeed = 0;
    int snakeYSpeed = 0;
    int score = 0;

    //Initalize an array of zeros
    int snakeX[3600] = {0};
    int snakeY[3600] = {0};

    static int gameSpeed;

    void Reset();
    void MoveSnake();
    void DrawSnake(QPainter *painter, int x, int y);
    void DrawFood(QPainter *painter, int x, int y);
    void DrawBounds(QPainter *painter);
    void Died();
    void CreateFood();
    void GetControls();
    void SetPlayerName(QString p1);

    QTimer *timer = new QTimer(this);
    QTimer *controlTimer = new QTimer(this);

private slots:
    void on_btn_exit_clicked();

private:
    Ui::MainWindow *ui;

    QString player_1;
};
#endif // MAINWINDOW_H
