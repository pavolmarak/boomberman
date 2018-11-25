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

private:
    Ui::GameUI *ui;
    QTimer *timer;
    QMap<int, bool> keys;
    bool eventFilter(QObject *obj, QEvent *event);
    QGraphicsPixmapItem* figure;
    QVector<QGraphicsPixmapItem*> bricks;
    QVector<QGraphicsPixmapItem*> yeses;
    QGraphicsScene* scene;
    qreal step;
    Map map;

private slots:
    void timerOutEvent();
};


#endif // KEYBOARD_H



