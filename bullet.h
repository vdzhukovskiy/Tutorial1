#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet:public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
    void hit();
};

#endif // BULLET_H
