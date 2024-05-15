#ifndef BRICK_H
#define BRICK_H

#include <QLabel>
#include <QVector>

class brick : public QObject
{

public:
    QLabel *bric;
    QVector<QVector<int>> briv;
    QLabel *pix;
    brick();
};

#endif // BRICK_H
