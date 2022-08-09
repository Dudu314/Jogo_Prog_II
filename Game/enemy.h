#ifndef ENEMY_H
#define ENEMY_H

//#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <QGraphicsPixmapItem>


class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H
