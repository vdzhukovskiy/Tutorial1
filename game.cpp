#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <player.h>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>

Game::Game(QWidget * parent): QGraphicsView(parent) {
    QGraphicsScene * scene =new QGraphicsScene();

    Player * player = new Player();
    player->setRect(0,0,100,100);

    scene->addItem(player);

    player->setFlags(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    player->setPos(view->width()/2 - player->rect().width()/2, view->height()-player->rect().height()+5);
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    QTimer * timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1500);
}














