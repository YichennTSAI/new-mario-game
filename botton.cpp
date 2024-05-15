#include "botton.h"

buttons::buttons(QString normalImg)
{
    this->normalImgPath = normalImg;
    QPixmap pix;
    pix.load(normalImg);
    this->setFixedSize(180, 90);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(200, 100));
}
