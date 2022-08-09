#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>


class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
    QAudioOutput * audio;
};

#endif // PLAYER_H
