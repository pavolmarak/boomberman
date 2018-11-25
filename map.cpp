#include "map.h"

Map::Map(QWidget *parent) : QWidget(parent)
{

}

Map::Map(Player &p):
    p(p)
{
}

const Player& Map::getP()
{
    return p;
}

void Map::setP(const Player &value)
{
    p = value;
}

QSize Map::getMap_size() const
{
    return map_size;
}

void Map::setMap_size(const QSize &value)
{
    map_size = value;
}

QVector<QPoint> Map::getYes_points() const
{
    return yes_points;
}

void Map::setYes_points(const QVector<QPoint> &value)
{
    yes_points = value;
}

QVector<QPoint> Map::getBrick_points() const
{
    return brick_points;
}

void Map::setBrick_points(const QVector<QPoint> &value)
{
    brick_points = value;
}
