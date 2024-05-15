#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1400, 800); // 設定螢幕尺寸
    this->setWindowTitle("Mario Game"); // 執行檔名


    buttons *start_btn = new buttons(":/Dataset/image/start_btn.png"); // 設置開始按鈕
    start_btn->setParent(this);
    start_btn->move(600, 560);

    connect(start_btn, &QPushButton::clicked, [=]()
    {
            this->hide();
            gaming *gamescene=new gaming;
                gamescene->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, 1400, 800, QPixmap(":/Dataset/image/start_screen.png")); // 開啟背景圖
}

