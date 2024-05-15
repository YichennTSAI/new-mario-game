#ifndef BOTTON_H
#define BOTTON_H

#include <QObject>
#include <QWidget>
#include <QObject>
#include<QPushButton>
#include<QString>

class buttons : public QPushButton
{
        Q_OBJECT
        public:

        buttons(QString normalImg);

            QString normalImgPath;

        private:

};

#endif // BOTTON_H
