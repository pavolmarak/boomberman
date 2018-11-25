#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QMap>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVector>
#include <QMultiMap>

#include "defaults.h"
#include "map.h"


namespace Ui {
class GameUI;
}

class GameEngine : public QWidget
{
    Q_OBJECT

public:
    explicit GameEngine(QWidget *parent = nullptr);
    ~GameEngine();

    Map *getMap() const;
    void setMap(Map *value);

private:
    Ui::GameUI *ui;
    QTimer *timer;
    QMap<int, bool> keys;
    qreal step;
    QGraphicsPixmapItem* figure;
    QMultiMap<QString,QGraphicsPixmapItem*> tiles;
    QGraphicsScene* scene;
    Player* player;
    Map* map;

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void timerOutEvent();
};


#endif // KEYBOARD_H



