#ifndef FLOWER_H
#define FLOWER_H

#include <QObject>
#include <QLabel>
#include <QVector>

class flower :public QObject
{
public:
    QVector<int> x;
    QVector<int> y;
    QVector<int> state;
    QLabel *pix;


    flower();
};

#endif // FLOWER_H
