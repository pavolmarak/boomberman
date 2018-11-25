#include "map.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>


Map::Map(Player* player, QSize map_size, QWidget *parent) :
    player(player),
    map_size(map_size),
    QWidget(parent)
{
}

Player *Map::getPlayer() const
{
    return player;
}

void Map::setPlayer(Player *value)
{
    player = value;
}

QSize Map::getMap_size() const
{
    return map_size;
}

void Map::setMap_size(const QSize &value)
{
    map_size = value;
}



void Map::loadLayoutFromFile(const QString &filepath)
{
    if(!QFile::exists(filepath)){
        throw MapNotLoadedException("File does not exist.");
    }
    QFile file(filepath);
    if(file.open(QFile::ReadOnly)){
        map_points.clear();
        QTextStream txt(&file);
        char tile;
        int row=0, col=0;
        while(!txt.atEnd()){
            txt >> tile;
            if(tile == YES_TILE){
                map_points.insert("yes",QPoint(col*TILE_SIZE,row*TILE_SIZE));
            }
            else if(tile == BRICK_TILE){
                map_points.insert("brick",QPoint(col*TILE_SIZE,row*TILE_SIZE));
            }
            else if(tile == IRON_TILE){
                map_points.insert("iron",QPoint(col*TILE_SIZE,row*TILE_SIZE));
            }
            else if(tile == END_LINE_TILE){
                col = 0;
                row++;
                continue;
            }
            col++;
        }
        file.close();
    }
    else{
        throw MapNotLoadedException("Problem opening file.");
    }

}

QMultiMap<QString, QPoint> Map::getMap_points() const
{
    return map_points;
}

void Map::setMap_points(const QMultiMap<QString, QPoint> &value)
{
    map_points = value;
}
