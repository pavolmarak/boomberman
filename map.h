#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QMultiMap>

#include "defaults.h"
#include "player.h"

class MapNotLoadedException{
    QString description;
public:
    MapNotLoadedException(QString description): description(description){}
    QString getDescription() const  { return description; }
};

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(Player* player = nullptr, QSize map_size = QSize(-1,-1), QWidget *parent = nullptr);

    Player *getPlayer() const;
    void setPlayer(Player *value);

    QSize getMap_size() const;
    void setMap_size(const QSize &value);

    QMultiMap<QString, QPoint> getMap_points() const;
    void setMap_points(const QMultiMap<QString, QPoint> &value);

    void loadLayoutFromFile(const QString& filepath);

signals:

public slots:

private:
    Player* player; // player object
    QSize map_size; // in px
    QMultiMap<QString,QPoint> map_points; // points in game map
};

#endif // MAP_H
