#ifndef FLAG_H
#define FLAG_H

#include <QObject>
#include <QLabel>
#include <QPropertyAnimation>


class flag:public QObject
{
public:
    flag();
    int x;
    int y;
    QLabel *pix;
    QPropertyAnimation *animation;

    bool move;

    void startmove();
};

#endif // FLAG_H
