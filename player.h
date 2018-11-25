#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QPixmap>
#include <QPoint>

class Player : public QObject
{
    Q_OBJECT
    class Item{

    };

public:
    explicit Player(QObject *parent = nullptr);

    Player(const Player& p);
    QPoint getPos() const;
    void setPos(const QPoint &value);

    const QMap<QString, QPixmap> &getFig_pixmaps();
    void setFig_pixmaps(const QMap<QString, QPixmap> &value);

signals:

public slots:
private:
    QPoint pos;
    QMap<QString,QPixmap> fig_pixmaps;
};

#endif // PLAYER_H
