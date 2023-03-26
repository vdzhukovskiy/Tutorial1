#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game * game;

Bullet::Bullet() {

    setRect(0,0,10,50);
    QTimer * timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(hit()));


    timer->start(50);
}

void Bullet::hit() {
    QList<QGraphicsItem *> collisions = scene()->collidingItems(this);

    for (int i = 0; i < collisions.size(); i++) {
        if (dynamic_cast<Enemy *>(collisions[i])) {
            game->score->increase();

            scene()->removeItem(collisions[i]);
            scene()->removeItem(this);
            delete collisions[i];
            delete this;
        }
    }
}

void Bullet::move() {
    setPos(x(),y()-10);

    if(pos().y() + this->rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
