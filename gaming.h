#ifndef GAMING_H
#define GAMING_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QFont>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QGraphicsScene>
#include <QTimer>
#include <QRect>
#include <vector>
#include <QPen>
#include <QString>
#include <cmath>


#include "background.h"
#include "floor.h"
#include "mario.h"
#include "brick.h"
#include "pipe.h"
#include "coin.h"
#include "pole.h"
#include "flag.h"
#include "flower.h"
#include "bullet.h"
#include "goomba.h"
#include "mushroom.h"


class gaming : public QWidget
{

public:
    gaming(QWidget *parent = nullptr);
    //~gaming();
    int viewX=0;
    QGraphicsScene * scene;

    background *back = new background;
    background ba;
    QVector<QLabel *> backlist;


    Floor *F= new Floor;
    Floor fl;
    QVector<QLabel *> Flist;

    pipe *P=new pipe;
    pipe pi;
    QVector<QLabel *> Plist;

    brick *B=new brick;
    brick br;
    QVector<QLabel *> Blist;

    coin *C=new coin;
    coin co;
    QVector<QLabel *> Clist;

    flower *fire=new flower;
    flower fi;
    QVector<QLabel *> Firelist;

    bullet *bul=new bullet;
    bullet bu;
    QVector<QLabel *> bullist;

    goomba *G=new goomba;
    goomba go;
    QVector<QLabel *> Glist;

    mushroom *m=new mushroom;
    mushroom mu;
    QVector<QLabel *> mlist;

    pole *po=new pole;
    flag *fla=new flag;

    mario *M=new mario;

    QLabel *outcome;

    QFont font,outfont;
    QPen pen;
    QLabel *scoreLabel;
    QLabel *lifeLabel;
    QLabel *bulletLabel;
    QLabel *winLabel;
    QLabel *winscoreLabel;



    int count=0;
    int mousex,mousey;

    bool collisionleft;
    bool collisionright;
    bool collisionup;
    bool collisiondown;

    void showbackground(QVector<QLabel *> &backlist,int x,int y);
    void showFloor(QVector<QLabel *> &Flist,int x,int y);
    void showMario(int x,int y);
    void showPipe(QVector<QLabel *> &Plist,int x,int y);
    void showbrick(QVector<QLabel *> &Blist,int x,int y,int z);
    void showcoin(QVector<QLabel *> &Clist,int x,int y);
    void showflower(QVector<QLabel *> &Firelist,int x,int y);
    void showflagpole();
    void showbullet(QVector<QLabel *> &bullist,int x,int y);
    void showgoomba(QVector<QLabel *> &Glist,int x,int y);
    void showmushroom(QVector<QLabel *> &mlist,int x,int y);
    void showoutcome();


    bool movescene=false;
    int hurttime;
    int length=5;
    bool hurt,fall=false,touch=true;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


public:slots
    void movescenes();  
    void movebullet();
    void movegoomba();
    void movemushroom();
    void hurted();
    void falling();
    void checkcollision();
};

#endif // GAMING_H
