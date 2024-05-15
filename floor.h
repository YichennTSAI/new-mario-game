#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>
#include <QLabel>
#include <QVector>
#include <QDebug>

class Floor:public QObject
{

public:
    QVector<int> hole;
    QLabel *pix;
    QVector<int>x;
    int y=520;

    Floor();
};

#endif // FLOOR_H
