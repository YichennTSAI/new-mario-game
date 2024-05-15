#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QLabel>
#include <QVector>

class bullet:public QObject
{
public:
    QVector<int> x;
    QVector<int> y;
    QVector<int> state;
    QVector<int> xspeed;
    QVector<int> yspeed;

    QLabel *pix;

    bool canmove;

    bullet();


};

#endif // BULLET_H
