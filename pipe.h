#ifndef PIPE_H
#define PIPE_H

#include <QLabel>
#include <QObject>
#include <QVector>

class pipe: public QObject
{

public:
    QLabel *pix;
    QVector<int>x;
    QVector<int>y;

    pipe();
};

#endif // PIPE_H
