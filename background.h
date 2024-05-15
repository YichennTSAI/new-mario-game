#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QLabel>
#include <QDebug>
#include <QVector>

class background:public QObject
{
public:
    background();

    QVector<int>x;
    QVector<int>y;
    QLabel *pix;
};

#endif // BACKGROUND_H
