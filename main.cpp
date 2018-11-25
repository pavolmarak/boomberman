#include "game_engine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try{
        GameEngine w;
        w.show();
        return a.exec();
    }
    catch(const MapNotLoadedException& e){
        qDebug() << e.getDescription();
        return EXIT_FAILURE;
    }
}
