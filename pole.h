#ifndef POLE_H
#define POLE_H

#include <QObject>
#include <QLabel>

class pole : public QObject
{
public:
    pole();
    int x;
    int y;
    QLabel *pix;
};

#endif // POLE_H
