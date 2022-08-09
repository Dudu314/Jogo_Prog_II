#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QAudioOutput>
Player::Player(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Images/player.png"));
    bulletsound = new QMediaPlayer();
    audio = new QAudioOutput();
    bulletsound->setAudioOutput(audio);
    bulletsound->setSource(QUrl("qrc:/sounds/Laser.mp3"));
    audio->setVolume(0.2);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"Key Pressed";
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x()>0)
            setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right)
    {
    if(pos().x() + 100 < 800 )
    setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Up)
    {
    setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down)
    {
    setPos(x(),y()+10);
    }
    else if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        if(bulletsound->playbackState() == QMediaPlayer::PlayingState)
         {
         // caso o som ainda esta tocando resetar o Player para posição
            bulletsound->setPosition(0);
             }
             else if(bulletsound->playbackState() == QMediaPlayer::StoppedState)
             {
             bulletsound->play();
             }
    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
