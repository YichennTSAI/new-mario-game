#ifndef MARSHROOM_H
#define MARSHROOM_H

#include <QLabel>
#include <QObject>
#include <QDebug>


class mushroom : public QObject
{

public:
    QVector<int> x;
    QVector<int> y;
    QVector<int> state;
    QVector<int> side1;
    QVector<int> side2;
    QLabel *pix;
    int move=-10;
    mushroom();
};
#endif // MARSHROOM_H
