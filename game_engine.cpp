#include "game_engine.h"
#include "ui_game.h"

GameEngine::GameEngine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameUI)
{
    ui->setupUi(this);
    step = 5;

    ui->graphicsView->installEventFilter(this);

    figure = new QGraphicsPixmapItem(map.getP().getFig_pixmaps().first());
    figure->setPos(0,0);

    scene = new QGraphicsScene();
    scene->addItem(figure);

    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    timer->setInterval(30);
    timer->start();
    connect(timer, &QTimer::timeout, this, &GameEngine::timerOutEvent);
}

GameEngine::~GameEngine()
{
    delete ui;
    delete figure;
    delete scene;
    delete timer;

}


void GameEngine::timerOutEvent()
{
    QString txt = "";

    if(keys[Qt::Key_Up])
    {
       txt += "_Up_";
       figure->setPixmap(map.getP().getFig_pixmaps()["up"]);
       figure->moveBy(0,-step);
    }
    if(keys[Qt::Key_Down])
    {
       txt += "_Down_";
       figure->setPixmap(map.getP().getFig_pixmaps()["down"]);
       figure->moveBy(0,+step);
    }
    if(keys[Qt::Key_Left])
    {
       txt += "_Left_";
       figure->setPixmap(map.getP().getFig_pixmaps()["left"]);
       figure->moveBy(-step,0);
    }
    if(keys[Qt::Key_Right])
    {
       txt += "_Right_";
       figure->setPixmap(map.getP().getFig_pixmaps()["right"]);
       figure->moveBy(+step,0);
    }

    qDebug() << scene->sceneRect();
    qDebug() << txt;
}


bool GameEngine::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        keys[keyEvent->key()] = true;
        //QWidget::keyPressEvent(keyEvent);
        return true;
    }
    else if(event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        keys[keyEvent->key()] = false;
        //QWidget::keyReleaseEvent(keyEvent);
        return true;
    }
    else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
