#include <QGraphicsTextItem>
#include <QTimer>
#include "game.h"
#include "enemy.h"
#include <QImage>
#include <QBrush>
#include <QMediaPlayer> // sudo apt-get install qtmultimedia5-dev
#include <QAudioOutput>


Game::Game(QWidget *parent)
{

    scene = new QGraphicsScene;

    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/Images/Background/starBackground.png")));

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(800,600);

    player = new Player();

    //player->setRect(0,0,100,100);

    player->setPos(400,500);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    QMediaPlayer * music = new QMediaPlayer(this);
    QAudioOutput * audioo = new QAudioOutput();
    music->setAudioOutput(audioo);

    music->setSource(QUrl("qrc:/sounds/Hall of the Mountain King.mp3"));
    audioo->setVolume(0.2);
    //connect(music,SIGNAL(playbackState()),music,SLOT(play()));
    music->play();
    show();

}

