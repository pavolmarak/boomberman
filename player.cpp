#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    fig_pixmaps.insert("up",QPixmap(PRO_PATH+QString("/img/up.png")));
    fig_pixmaps.insert("down",QPixmap(PRO_PATH+QString("/img/down.png")));
    fig_pixmaps.insert("left",QPixmap(PRO_PATH+QString("/img/left.png")));
    fig_pixmaps.insert("right",QPixmap(PRO_PATH+QString("/img/right.png")));
}

QPoint Player::getPos() const
{
    return pos;
}

void Player::setPos(const QPoint &value)
{
    pos = value;
}

const QMap<QString, QPixmap>& Player::getFig_pixmaps() const
{
    return fig_pixmaps;
}

void Player::setFig_pixmaps(const QMap<QString, QPixmap> &value)
{
    fig_pixmaps = value;
}
