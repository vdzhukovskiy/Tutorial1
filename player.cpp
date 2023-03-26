#include "player.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <enemy.h>


void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left && pos().x()>=10) {
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right && pos().x() + rect().width() < 800) {
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space) {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()  + 45 ,y());
        scene()->addItem(bullet);
    }
}

void Player::spawn() {
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
