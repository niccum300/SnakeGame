#include "main.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    Game snake_game;
    std::cout<<"Creating Windows..."<<std::endl;
    snake_game.createWindow(0, 1920, 1080);

    std::cout<<"Populating Map..."<<std::endl;
    snake_game.populateMap(1.0f, 1.0f, 10, 10);

    std::cout<<"Binding Map with Windows..."<<std::endl;
    snake_game.bindMapWindow(0);

    std::cout<<"Running Game..."<<std::endl;
    snake_game.run();


    return a.exec();
}
