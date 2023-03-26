#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "game.h"

extern Game * game;

Enemy::Enemy() {
    int x_position = rand() % 700;
    setPos(x_position, 0);

    setRect(0,0,100,100);

    QTimer * timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move() {
    setPos(x(),y()+5);

    if(pos().y() + this->rect().height() > 700) {
        if (game->health->getHealth() > 0){
            game->health->decrease();
        }

        scene()->removeItem(this);
        delete this;
    }
}

