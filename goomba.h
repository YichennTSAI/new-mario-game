#ifndef GOOMBA_H
#define GOOMBA_H

#include <QObject>
#include <QVector>
#include <QLabel>

class goomba:public QObject
{
public:
    QVector<int> x;
    QVector<int> y;
    QVector<int> state;
    QVector<int> leftside;
    QVector<int> rightside;
    QVector<int> move;
    QVector<int> direction;

    QLabel *pix;
    goomba();
};

#endif // GOOMBA_H
