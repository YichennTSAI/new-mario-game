#include "gaming.h"

gaming::gaming(QWidget *parent)
{

    setWindowTitle("start");
    setFixedSize(1400, 620);
    setFocusPolicy(Qt::StrongFocus);

    collisionleft=false;
    collisionright=false;
    collisionup=false;
    collisiondown=false;
    hurt=false;
    hurttime=0;

    ba.pix = new QLabel(this);
    backlist.push_back(ba.pix);

    for(int i=1;i<=back->x.size();i++)
    {
        showbackground(backlist,back->x[i-1],back->y[i-1]);
    }


    fl.pix=new QLabel(this);
    Flist.push_back(fl.pix);
    for(int i=1;i<F->x.size();i++)
    {
        showFloor(Flist,F->x[i-1],520);
    }



    P->pix=new QLabel(this);
    Plist.push_back(pi.pix);
    for(int i=1;i<P->x.size()+1;i++)
    {
        showPipe(Plist,P->x[i-1],P->y[i-1]);
    }

    br.pix=new QLabel(this);
    Blist.push_back(br.pix);


    for(int i=1;i<B->briv.size()+1;i++)
    {
        showbrick(Blist,B->briv[i-1][0],B->briv[i-1][1],B->briv[i-1][2]);
    }

    co.pix=new QLabel(this);
    Clist.push_back(co.pix);
    for(int i=1;i<C->x.size();i++)
    {
        if(C->state[i-1]==1)
        showcoin(Clist,C->x[i-1],C->y[i-1]);
    }

    fi.pix=new QLabel(this);
    Firelist.push_back(fi.pix);

    mu.pix=new QLabel(this);
    mlist.push_back(mu.pix);

    bu.pix=new QLabel(this);
    bullist.push_back(bu.pix);

    go.pix=new QLabel(this);
    Glist.push_back(go.pix);
    for(int i=0;i<G->x.size();i++)
    {
        showgoomba(Glist,G->x[i],G->y[i]);
    }

    showflagpole();

    showMario(M->x,M->y);


    font.setPointSize(20);
    scoreLabel=new QLabel(this);
    scoreLabel->setFont(font);
    scoreLabel->setText(QString("Score: %1").arg(1000));
    scoreLabel->move(100,0);
    scoreLabel->show(); // 顯示 QLabel

    lifeLabel=new QLabel(this);
    lifeLabel->setFont(font);
    lifeLabel->setText(QString("HP: %1").arg(M->life));
    lifeLabel->move(0,0);
    lifeLabel->show(); // 顯示 QLabel

    bulletLabel=new QLabel(this);
    bulletLabel->setFont(font);
    bulletLabel->setText(QString("bullet: %1").arg(0));
    bulletLabel->move(250,0);
    bulletLabel->show(); // 顯示 QLabel



    QTimer *timer1=new QTimer(this);
    connect(timer1,&QTimer::timeout,this,&gaming::movescenes);
    connect(timer1,&QTimer::timeout,M,&mario::moveright);
    connect(timer1,&QTimer::timeout,M,&mario::moveleft);
    timer1->start(2);                                   //移動的timer

    QTimer *timer2=new QTimer(this);
    connect(timer2,&QTimer::timeout,M,&mario::jump);
    timer2->start(20);                                  //跳的timer

    QTimer *timer3=new QTimer(this);
    connect(timer3,&QTimer::timeout,this,&gaming::checkcollision);
    timer3->start(1);

    QTimer *timer4=new QTimer(this);
    connect(timer4,&QTimer::timeout,fla,&flag::startmove);
    timer4->start(20);                                  //旗子落下

    QTimer *timer5=new QTimer(this);
    connect(timer5,&QTimer::timeout,this,&gaming::movebullet);
    connect(timer5,&QTimer::timeout,this,&gaming::movegoomba);
    connect(timer5,&QTimer::timeout,this,&gaming::movemushroom);
    timer5->start(20);                                  //子彈移動*/

    QTimer *timer6=new QTimer(this);
    connect(timer6,&QTimer::timeout,this,&gaming::hurted);
    timer6->start(1000);
}
void gaming::showbackground(QVector<QLabel *> &backlist,int x,int y)
{
    ba.pix = new QLabel(this);
    ba.pix->setStyleSheet("border-image: url(:/Dataset/image/background.png);");
    ba.pix->setGeometry(x,y,1400,620);
    ba.pix->show();
    backlist.push_back(ba.pix);
}

void gaming::showFloor(QVector<QLabel *> &Flist,int x,int y)
{
    fl.pix=new QLabel(this);
    fl.pix->setStyleSheet("border-image: url(:/Dataset/image/brick/floor brick.png)");
    fl.pix->setGeometry(x,y,50,100);
    fl.pix->show();
    Flist.push_back(fl.pix);
}
void gaming::showMario(int x,int y)
{
    M->pix=new QLabel(this);
    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_stand_R.png)");
    M->pix->setGeometry(x,y,M->xsize,M->ysize);
    M->pix->show();

}
void gaming::showPipe(QVector<QLabel *> &Plist,int x,int y)
{
    pi.pix=new QLabel(this);
    pi.pix->setStyleSheet("border-image: url(:/Dataset/image/brick/water pipe.png)");
    pi.pix->setGeometry(x,y,100,520-y);
    pi.pix->show();
    Plist.push_back(pi.pix);
}

void gaming::showbrick(QVector<QLabel *> &Blist,int x,int y,int z)
{
    br.pix=new QLabel(this);
    switch(z)
    {
        case -1:
        br.pix->setStyleSheet("border-image: url(:/Dataset/image/brick/broken brick.png)");
        break;
        case 0:
        br.pix->setStyleSheet("border-image: url(:/Dataset/image/brick/stone brick.png)");
        break;
        case 1:
        br.pix->setStyleSheet("border-image: url(:/Dataset/image/brick/normal brick.png)");
        break;
        case 2:
        br.pix->setStyleSheet("border-image: url(:/Dataset/image/brick/box brick.png)");
        break;
    }
    br.pix->setGeometry(x,y,50,50);
    br.pix->show();
    Blist.push_back(br.pix);
}

void gaming::showcoin(QVector<QLabel *> &Clist,int x,int y)
{
    co.pix=new QLabel(this);
    co.pix->setStyleSheet("border-image: url(:/Dataset/image/item/coin.png)");
    co.pix->setGeometry(x,y,50,50);
    co.pix->show();
    Clist.push_back(co.pix);
}

void gaming::showflower(QVector<QLabel *> &Firelist,int x,int y)
{
    fire->x.push_back(x);
    fire->y.push_back(y);
    fire->state.push_back(1);

    fi.pix=new QLabel(this);
    fi.pix->setStyleSheet("border-image: url(:/Dataset/image/item/Fire Flower.png);");
    fi.pix->setGeometry(x,y,50,50);
    fi.pix->show();
    Firelist.push_back(fi.pix);


}


void gaming::showbullet(QVector<QLabel *> &bullist,int x,int y)
{
    bul->x.push_back(x);
    bul->y.push_back(y);
    bul->state.push_back(1);

    bu.pix=new QLabel(this);
    bu.pix->setStyleSheet("border-image: url(:/Dataset/image/bullet.png);");
    bu.pix->setGeometry(x,y,20,20);
    bu.pix->show();
    bullist.push_back(bu.pix);
}

void gaming::showgoomba(QVector<QLabel *> &Glist,int x,int y)
{
    go.pix=new QLabel(this);
    go.pix->setStyleSheet("border-image: url(:/Dataset/image/toxic mushroom1.png);");
    go.pix->setGeometry(x,y,50,50);
    go.pix->show();
    Glist.push_back(go.pix);

}
void gaming::showmushroom(QVector<QLabel *> &mlist,int x,int y)
{
    m->x.push_back(x);
    m->y.push_back(y);
    m->state.push_back(1);

    mu.pix=new QLabel(this);
    mu.pix->setStyleSheet("border-image: url(:/Dataset/image/item/super mushroom.png);");
    mu.pix->setGeometry(x,y,50,50);
    mu.pix->show();
    mlist.push_back(mu.pix);
}

void gaming::showflagpole()
{
    po->pix=new QLabel(this);
    po->pix->setStyleSheet("border-image: url(:/Dataset/image/item/flag-pole.png)");
    po->pix->setGeometry(po->x,po->y,15,500);
    po->pix->show();
    fla->pix=new QLabel(this);
    fla->pix->setStyleSheet("border-image: url(:/Dataset/image/item/flag.png)");
    fla->pix->setGeometry(fla->x,fla->y,60,60);
    fla->pix->show();
}

void gaming::checkcollision()
{

    //M->canjump=false;
    if(M->y>620)
    {
        showoutcome();
        winLabel->setText("Game Over");
        winscoreLabel->setText("in the hole");
        winLabel->show();
        winscoreLabel->show();
        M->bul=0;
    }

    QRect marioitem(M->x,M->y,M->xsize,M->ysize);

    collisionleft=false;
    collisionright=false;
    collisionup=false;
    for(int i=0;i<P->x.size();i++)
    {
        QRect pipeitem(P->x[i],P->y[i],100,520-P->y[i]);

        if(marioitem.intersects(pipeitem))
        {
            if(!M->canjump&&M->y<P->y[i])
            {
                M->yspeed=0;
                M->y=P->y[i]-M->ysize-1;
                M->pix->move(QPoint(M->x,P->y[i]-M->ysize-1));
                M->canjump=true;
                collisiondown=true;
            }
            else if(M->x<P->x[i]&&!M->canmoveright)
            {
                collisionright=true;


                M->canmoveright=false;
                movescene=false;
                M->pix->move(QPoint(P->x[i]-M->xsize+1,M->y));
                M->x=P->x[i]-M->xsize+1;
            }
            else if(M->x>P->x[i]&&!M->canmoveleft)
            {
                collisionleft=true;

                M->canmoveleft=false;
                movescene=false;
                M->pix->move(QPoint(P->x[i]+99,M->y));
                M->x=P->x[i]+99;
            }
        }

    }
    for(int i=0;i<F->x.size();i++)
    {
        QRect flooritem(F->x[i],520,50,100);

        if(marioitem.intersects(flooritem))
        {
            if(!M->canjump&&M->y+M->ysize>520)
            {
                M->yspeed=0;
                M->y=520-M->ysize-1;
                M->pix->move(QPoint(M->x,520-M->ysize-1));
                M->canjump=true;
                collisiondown=true;
            }
        }

    }

    for(int i=0;i<B->briv.size();i++)
    {
        QRect brickitem(B->briv[i][0]+2,B->briv[i][1]+2,44,44);
        if(marioitem.intersects(brickitem)&&B->briv[i][2]!=-2)
        {
            if(M->y<B->briv[i][1]+50&&M->yspeed<0)
            {
                M->yspeed=0;
                M->y=B->briv[i][1]+51;
                M->pix->move(QPoint(M->x,B->briv[i][1]+51));
                switch (B->briv[i][2])
                {
                case -1:
                    B->briv[i][2]=-2;
                    Blist[i+1]->hide();
                    break;
                case 1:
                    B->briv[i][2]=0;
                    Blist[i+1]->setStyleSheet("border-image: url(:/Dataset/image/brick/stone brick.png)");
                    break;
                case 2:
                    B->briv[i][2]=0;
                    Blist[i+1]->setStyleSheet("border-image: url(:/Dataset/image/brick/stone brick.png)");
                    if(i%2==0)
                    showflower(Firelist,B->briv[i][0],B->briv[i][1]-50);
                    else
                    showmushroom(mlist,B->briv[i][0],B->briv[i][1]-50);
                    break;
                default:
                    break;
                }
            }
            else if(!M->canjump&&M->y+M->ysize>B->briv[i][1]&&M->yspeed>0)
            {
                M->yspeed=0;
                M->y=B->briv[i][1]-M->ysize-1;
                M->pix->move(QPoint(M->x,B->briv[i][1]-M->ysize-1));
                M->canjump=true;
                collisiondown=true;
            }
            else if(M->x<B->briv[i][0]&&!M->canmoveright&&M->canjump&&M->y<515)
            {
                collisionright=true;


                M->canmoveright=false;
                movescene=false;
                M->pix->move(QPoint(B->briv[i][0]-M->xsize,M->y));
                M->x=B->briv[i][0]-M->xsize;
            }
            else if(M->x>B->briv[i][0]&&!M->canmoveleft&&M->canjump&&M->y<515)
            {
                collisionleft=true;

                M->canmoveleft=false;
                movescene=false;
                M->pix->move(QPoint(B->briv[i][0]+50,M->y));
                M->x=B->briv[i][0]+50;
            }
            else
                ;
        }
    }

    for(int i=0;i<C->x.size();i++)
    {
        QRect coinitem(C->x[i],C->y[i],50,50);
        if(marioitem.intersects(coinitem)&&C->state[i]==1)
        {
            Clist[i+1]->hide();
            M->score+=10;
            C->state[i]=0;
            scoreLabel->setText(QString("Score: %1").arg(M->score));
            if(M->score==200)
            {
                showoutcome();
                winLabel->setText("You Win");
                winscoreLabel->setText(QString("Score: %1").arg(M->score));
                M->score+=10;
                winLabel->show();
                winscoreLabel->show();
                M->bul=0;
                gaming *gamescene=new gaming;
                gamescene->show();
            }
        }
    }
    for(int i=0;i<m->x.size();i++)
    {
        QRect mushroomitem(m->x[i],m->y[i],50,50);
        if(marioitem.intersects(mushroomitem)&&m->state[i]==1)
        {
            mlist[i+1]->hide();
            m->state[i]=0;
            M->state=2;
            M->xsize=56;
            M->ysize=80;
            M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_run0.png);");
            M->pix->setGeometry(M->x,M->y,M->xsize,M->ysize);

        }
    }
    for(int i=0;i<fire->x.size();i++)
    {
        QRect fireitem(fire->x[i],fire->y[i],50,50);
        if(marioitem.intersects(fireitem)&&fire->state[i]==1)
        {
            Firelist[i+1]->hide();
            M->bul=3;
            fire->state[i]=0;
            update();
            bulletLabel->setText(QString("bullet: %1").arg(M->bul));
        }
    }

    for(int j=1;j<Glist.size();j++)
    {
        QRect goombaitem(G->x[j-1],G->y[j-1],50,50);
        if(marioitem.intersects(goombaitem)&&G->state[j-1]==1)
        {

            if(!M->canjump&&M->y+M->ysize>G->y[j-1]&&M->yspeed>0)
            {
                M->yspeed=0;
                M->y=520-M->ysize;
                M->pix->move(QPoint(M->x,520-M->ysize));
                M->canjump=true;
                collisiondown=true;
                Glist[j]->setStyleSheet("border-image: url(:/Dataset/image/toxic mushroom3.png);");
                G->state[j-1]=0;
            }
            else if(hurt==false)
            {
                hurt=true;
                hurttime=1;
                if(M->state==2)
                {
                    M->state=1;
                    M->xsize=50;
                    M->ysize=50;
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run1_R.png);");
                    M->pix->setGeometry(M->x,M->y+30,M->xsize,M->ysize);

                }
                else if(M->state==1&&M->life>1)
                {
                    showoutcome();
                    winLabel->setText("You Lose 1 HP");
                    winscoreLabel->setText(QString("Score: %1").arg(M->score));
                    winLabel->show();
                    winscoreLabel->show();
                    M->bul=0;
                    G->state[j-1]=0;
                    gaming *gamescene=new gaming;
                    gamescene->M->life-=1;
                    gamescene->show();
                }
                else if(M->state==1&&M->life==1)
                {
                    showoutcome();
                    winLabel->setText("Game Over");
                    winscoreLabel->setText(QString("Score: %1").arg(M->score));
                    winLabel->show();
                    winscoreLabel->show();
                    M->bul=0;
                    G->state[j-1]=0;
                }

            }
        }
    }
    QRect poleitem(po->x,po->y,15,500);
    if(marioitem.intersects(poleitem))
    {
        if(fla->move==true&&fla->y>400)
        {
            M->pix->move(QPoint(po->x-M->xsize-5,470));
            M->x=po->x-M->xsize-5;
            M->y=470;

            showoutcome();
            winLabel->setText("You Win");
            winscoreLabel->setText("Reach the flag");
            winLabel->show();
            winscoreLabel->show();
            M->bul=0;
            fla->move=false;
            gaming *gamescene=new gaming;
            gamescene->show();
        }
        if(fla->move==false&&fla->y<400)
        fla->move=true;

    }
    for(int i=1;i<bullist.size();i++)
    {
        QRect bulletitem(bul->x[i-1],bul->y[i-1],20,20);
        for(int j=1;j<Blist.size();j++)
        {
            QRect brickitem(B->briv[j-1][0],B->briv[j-1][1],50,50);
            if(bulletitem.intersects(brickitem)&&B->briv[j-1][2]>-2)
            {
                bullist[i]->hide();
                bul->state[i-1]=0;
            }
        }
        for(int j=1;j<Plist.size();j++)
        {
            QRect pipeitem(P->x[j-1],P->y[j-1],100,520-P->y[j-1]);
            if(bulletitem.intersects(pipeitem))
            {
                bullist[i]->hide();
                bul->state[i-1]=0;
            }
        }
        for(int j=1;j<Flist.size();j++)
        {
            QRect flooritem(F->x[j-1],520,50,100);
            if(bulletitem.intersects(flooritem))
            {
                bullist[i]->hide();
                bul->state[i-1]=0;
            }
        }
        for(int j=1;j<Glist.size();j++)
        {
            QRect goombaitem(G->x[j-1],G->y[j-1],50,50);
            if(bulletitem.intersects(goombaitem)&&G->state[j-1]==1&&bul->state[i-1]==1)
            {
                bullist[i]->hide();
                bul->state[i-1]=0;
                Glist[j]->setStyleSheet("border-image: url(:/Dataset/image/toxic mushroom3.png);");
                G->state[j-1]=0;
            }
        }
    }
}
void gaming::keyPressEvent(QKeyEvent *event)
{
    checkcollision();
    if(event->key()==Qt::Key_Right)
    {
        count++;

        M->direction=2;
        if(M->swift==0)
            M->swift=1;
        if(count>=2&&M->canjump)
        {
            if(M->state==1)
            {
                if(M->swift==1)
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run1_R.png);");
                    M->swift=2;
                }
                else
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run2_R.png);");
                    M->swift=1;
                }
            }
            else
            {
                if(M->swift==1)
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_run0.png);");
                    M->swift=2;
                }
                else if(M->swift==2)
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_run1.png);");
                    M->swift=3;
                }
                else
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_run2.png);");
                    M->swift=1;
                }
            }
            count=0;
        }
        else if(count>=1&&!M->canjump)
        {
            if(M->state==1)
            {
                if(M->yspeed>0)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump2_R.png);");
                else if(M->yspeed<0)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump1_R.png);");
                else
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run1_R.png);");
            }
            else
            {
                if(M->yspeed>=10)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump4.png);");
                else if(M->yspeed>=0)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump3.png);");
                else if(M->yspeed>=-10)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump2.png);");
                else
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump1.png);");
            }
            count=0;
        }

        if(!collisionright)
        {
            checkcollision();
            M->open=true;
            if(M->atmid()&&viewX<6200)
            movescene=true;
            else
            M->canmoveright=true;
        }
    }
    if(event->key()==Qt::Key_Left)
    {
        count++;
        M->direction=1;
        if(M->swift==0)
            M->swift=1;

        if(count>=2&&M->canjump)
        {

            if(M->state==1)
            {
                if(M->swift==1)
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run1_L.png);");
                    M->swift=2;
                }
                else
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run2_L.png);");
                    M->swift=1;
                }
            }
            else
            {
                if(M->swift==1)
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_run0.png);");
                    M->swift=2;
                }
                else if(M->swift==2)
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_run1.png);");
                    M->swift=3;
                }
                else
                {
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_run2.png);");
                    M->swift=1;
                }
            }
            count=0;
        }
        else if(count>=1&&!M->canjump)
        {
            count++;
            if(M->state==1)
            {
                if(M->yspeed>0)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump2_L.png);");
                else if(M->yspeed<0)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump1_L.png);");
                else
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run1_L.png);");
            }
            else
            {
                if(M->yspeed>=10)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump4.png);");
                else if(M->yspeed>=0)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump3.png);");
                else if(M->yspeed>=-10)
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump2.png);");
                else
                    M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump1.png);");
            }
            count=0;
        }
        checkcollision();
        if(!collisionleft)
        {
            M->canmoveleft=true;
            M->open=true;
        }

    }
    if(event->key()==Qt::Key_Up)
    {
        checkcollision();
        if(M->canjump)
        {
            if(M->state==1)
                M->yspeed-=30;
            else
                M->yspeed-=40;
        }
        M->canjump=false;

        if(count>=1&&!M->canjump)
        {
            if(M->direction==1)
            {
                if(M->state==1)
                {
                    if(M->yspeed>0)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump2_L.png);");
                    else if(M->yspeed<0)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump1_L.png);");
                    else
                       M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run1_L.png);");
                }
                else
                {
                    if(M->yspeed>=10)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump4.png);");
                    else if(M->yspeed>=0)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump3.png);");
                    else if(M->yspeed>=-10)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump2.png);");
                    else
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_L_jump1.png);");
                }
            }
            else
            {
                if(M->state==1)
                {
                    if(M->yspeed>0)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump2_R.png);");
                    else if(M->yspeed<0)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_jump1_R.png);");
                    else
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_small/s_mario_run1_R.png);");
                }
                else
                {
                    if(M->yspeed>=10)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump4.png);");
                    else if(M->yspeed>=0)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump3.png);");
                    else if(M->yspeed>=-10)
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump2.png);");
                    else
                        M->pix->setStyleSheet("border-image: url(:/Dataset/image/Mario_big/mario_R_jump1.png);");
                }
            }
            count=0;
        }
    }

}
void gaming::keyReleaseEvent(QKeyEvent *event)
{
    checkcollision();
    M->open=false;
    if(event->key()==Qt::Key_Right)
    {
        checkcollision();
        movescene=false;
        M->canmoveright=false;
    }
    if(event->key()==Qt::Key_Left)
    {
        checkcollision();
        M->canmoveleft=false;

    }
    if(event->key()==Qt::Key_Up)
    {
        checkcollision();
    }
}

void gaming::movescenes()
{
    if(movescene)
    {
        for (int i = 1; i < backlist.size(); ++i)
        {
            backlist[i]->move(backlist[i]->x() - 1, backlist[i]->y());
        }
        for(int i=1;i<Flist.size();i++)
        {
            Flist[i]->move(Flist[i]->x()-1,Flist[i]->y());
            F->x[i-1]-=1;
        }
        for(int i=1;i<Plist.size();i++)
        {
            Plist[i]->move(Plist[i]->x()-1,Plist[i]->y());
            P->x[i-1]-=1;
        }
        for(int i=1;i<Blist.size();i++)
        {
            Blist[i]->move(Blist[i]->x()-1,Blist[i]->y());
            B->briv[i-1][0]-=1;
        }
        for(int i=1;i<Clist.size();i++)
        {
            Clist[i]->move(Clist[i]->x()-1,Clist[i]->y());
            C->x[i-1]-=1;
        }
        for(int i=1;i<Firelist.size();i++)
        {
            Firelist[i]->move(Firelist[i]->x()-1,Firelist[i]->y());
            fire->x[i-1]-=1;
        }
        for(int i=1;i<bullist.size();i++)
        {
            bullist[i]->move(bullist[i]->x()-1,bullist[i]->y());
            bul->x[i-1]-=1;
        }


        for(int i=1;i<Glist.size();i++)
        {
            Glist[i]->move(Glist[i]->x()-1,Glist[i]->y());
            G->x[i-1]-=1;
            G->leftside[i-1]-=1;
            G->rightside[i-1]-=1;
        }

        for(int i=1;i<mlist.size();i++)
        {
            mlist[i]->move(mlist[i]->x()-1,mlist[i]->y());
            m->x[i-1]-=1;
        }


        po->pix->move(po->x-1,po->y);
        po->x-=1;
        fla->pix->move(fla->x-1,fla->y);
        fla->x-=1;


        viewX+=1;
    }
}

void gaming::mousePressEvent(QMouseEvent *event)
{
    mouseMoveEvent(event);
    if(event->button()==Qt::LeftButton&&M->bul>0)
    {

        M->bul-=1;
        bulletLabel->setText(QString("bullet: %1").arg(M->bul));
        showbullet(bullist,M->x+20,M->y+15);
        bul->xspeed.push_back((mousex-M->x-20)/50);
        bul->yspeed.push_back((mousey-M->y-15)/50);
    }
}
void gaming::mouseMoveEvent(QMouseEvent *event)
{
    mousex=event->x();
    mousey=event->y();
}

void gaming::movebullet()
{
    for(int i=1;i<bullist.size();i++)
    {
        if(bul->state[i-1]==1)
        {
            bullist[i]->move(bullist[i]->x()+bul->xspeed[i-1],bullist[i]->y()+bul->yspeed[i-1]);
            bul->x[i-1]+=bul->xspeed[i-1];
            bul->y[i-1]+=bul->yspeed[i-1];
        }
    }
}
void gaming::movegoomba()
{
    for(int i=1;i<Glist.size();i++)
    {
        if(G->state[i-1]==1)
        {
            if(G->x[i-1]>G->rightside[i-1]||G->x[i-1]<G->leftside[i-1])
            {
                G->move[i-1]=-G->move[i-1];
                if(G->direction[i-1]==1)
                {
                    G->direction[i-1]=2;
                    Glist[i]->setStyleSheet("border-image: url(:/Dataset/image/toxic mushroom2.png);");
                }
                else
                {
                    Glist[i]->setStyleSheet("border-image: url(:/Dataset/image/toxic mushroom1.png);");
                    G->direction[i-1]=1;
                }
            }

            Glist[i]->move(Glist[i]->x()+G->move[i-1],Glist[i]->y());
            G->x[i-1]+=G->move[i-1];
        }
    }
}
void gaming::movemushroom()
{
    for(int i=1;i<mlist.size();i++)
    {
        if(m->side1[i-1]>0||m->side2[i-1]<0)
        {
            m->move=-m->move;

        }
        if(m->side1[i-1]==m->side2[i-1]&&m->side1[i-1]==0)
            ;
        else
        {
            m->side2[i-1]+=m->move;
            m->side1[i-1]+=m->move;
            mlist[i]->move(mlist[i]->x()-m->move,mlist[i]->y());
            m->x[i-1]-=m->move;
        }

    }
}
void gaming::hurted()
{
    qDebug()<<hurttime<<endl;
    if(hurttime>=1)
        hurttime++;
    if(hurttime==3)
    {
        hurttime=0;
        hurt=false;
    }
}

void gaming::showoutcome()
{
    outcome=new QLabel(this);
    outcome->setStyleSheet("border-image: url(:/Dataset/image/forest1.png);");
    outcome->setGeometry(0,0,1400,620);
    outcome->show();
    winLabel=new QLabel(this);
    winscoreLabel=new QLabel(this);
    winscoreLabel->setStyleSheet("color: black; font-size: 50px;");
    winLabel->setStyleSheet("color: black; font-size: 50px;");
    winLabel->move(600,0);
    winscoreLabel->move(600,50);
}
void gaming::falling()
{
    if(fall)
    {
        M->pix->move(M->pix->x(),M->pix->y()+M->yspeed);
        M->y+=M->yspeed;
        M->yspeed+=4;
    }
}

