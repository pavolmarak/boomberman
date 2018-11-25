#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QVector>
#include <QPoint>

#include "player.h"

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);

    Map(Player& p);

    const Player &getP();
    void setP(const Player &value);

    QSize getMap_size() const;
    void setMap_size(const QSize &value);

    QVector<QPoint> getYes_points() const;
    void setYes_points(const QVector<QPoint> &value);

    QVector<QPoint> getBrick_points() const;
    void setBrick_points(const QVector<QPoint> &value);

signals:

public slots:

private:
    Player p;
    QSize map_size; // in px
    QVector<QPoint> yes_points;
    QVector<QPoint> brick_points;
};

#endif // MAP_H
