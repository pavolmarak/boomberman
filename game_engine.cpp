#include "game_engine.h"
#include "ui_game.h"


GameEngine::GameEngine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameUI)
{
    ui->setupUi(this);
    step = TILE_SIZE;

    ui->view->installEventFilter(this);

    player = new Player;
    map = new Map(player);

    QString map_layout_file = PRO_PATH+QString("/map.txt");
    try{
        map->loadLayoutFromFile(map_layout_file);
    }
    catch(const MapNotLoadedException& e){
        qDebug() << e.getDescription();
        throw; // rethrow
    }

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,TILE_COUNT_X*TILE_SIZE,TILE_COUNT_Y*TILE_SIZE);
    scene->setBackgroundBrush(QBrush(Qt::gray));

    QList<QPoint> yp = map->getMap_points().values("yes");
    QList<QPoint> bp = map->getMap_points().values("brick");
    QList<QPoint> ip = map->getMap_points().values("iron");

    // set up items
    for(QPoint p : yp){
        QGraphicsPixmapItem* pi = new QGraphicsPixmapItem(QPixmap(PRO_PATH+QString("/img/yes.png")));
        pi->setPos(p);
        tiles.insert("yes",pi);
        scene->addItem(pi);
    }
    for(QPoint p : bp){
        QGraphicsPixmapItem* pi = new QGraphicsPixmapItem(QPixmap(PRO_PATH+QString("/img/brick.png")));
        pi->setPos(p);
        tiles.insert("brick",pi);
        scene->addItem(pi);
    }
    for(QPoint p : ip){
        QGraphicsPixmapItem* pi = new QGraphicsPixmapItem(QPixmap(PRO_PATH+QString("/img/iron.png")));
        pi->setPos(p);
        tiles.insert("iron",pi);
        scene->addItem(pi);
    }


    // create player
    figure = new QGraphicsPixmapItem(QPixmap(PRO_PATH+QString("/img/hero.png")));
    figure->setPos(yp.first());
    scene->addItem(figure);

    ui->view->setScene(scene);


    timer = new QTimer();
    timer->setInterval(TIMEOUT_INTERVAL);
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

Map *GameEngine::getMap() const
{
    return map;
}

void GameEngine::setMap(Map *value)
{
    map = value;
}

void GameEngine::timerOutEvent()
{
    QString txt = "";

    if(keys[Qt::Key_Up])
    {
       txt += "_Up_";
       //figure->setPixmap(map->getPlayer()->getFig_pixmaps()["up"]);

       if(map->getMap_points().values("yes").contains(figure->pos().toPoint()+QPoint(0,-step))){
            figure->moveBy(0,-step);
       }
       qDebug() << txt;
    }
    if(keys[Qt::Key_Down])
    {
       txt += "_Down_";
       //figure->setPixmap(map->getPlayer()->getFig_pixmaps()["down"]);
       if(map->getMap_points().values("yes").contains(figure->pos().toPoint()+QPoint(0,+step))){
            figure->moveBy(0,+step);
       }
       qDebug() << txt;
    }
    if(keys[Qt::Key_Left])
    {
       txt += "_Left_";
       //figure->setPixmap(map->getPlayer()->getFig_pixmaps()["left"]);
       if(map->getMap_points().values("yes").contains(figure->pos().toPoint()+QPoint(-step,0))){
            figure->moveBy(-step,0);
       }
       qDebug() << txt;
    }
    if(keys[Qt::Key_Right])
    {
       txt += "_Right_";
       //figure->setPixmap(map->getPlayer()->getFig_pixmaps()["right"]);
       if(map->getMap_points().values("yes").contains(figure->pos().toPoint()+QPoint(+step,0))){
            figure->moveBy(+step,0);
       }
       qDebug() << txt;
    }
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
