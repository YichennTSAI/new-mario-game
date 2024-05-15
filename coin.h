#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QVector>
#include <QLabel>


class coin : public QObject
{
public:
    coin();
    QVector<int>x;
    QVector<int>y;
    QVector<int>state;
    QLabel *pix;
};

#endif // COIN_H
