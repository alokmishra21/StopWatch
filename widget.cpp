#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->stop, SIGNAL(clicked(bool)), this, SLOT(slot_stop()));
    connect(ui->play, SIGNAL(clicked(bool)), this, SLOT(slot_play()));
    connect(ui->pause, SIGNAL(clicked(bool)), this, SLOT(slot_pause()));
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slot_update()));
    m_timer->start(1000);
    m_time_hrs = 0;
    m_time_mins = 0;
    m_time_secs = 0;
    is_paused = false;
    this->setGeometry(400, 200, this->width(), this->height());
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
}

void Widget::slot_play()
{
    is_paused = false;
    std::cout << "play" << std::endl;
}

void Widget::slot_pause()
{
    is_paused = true;
    std::cout << "pause" << std::endl;
}

void Widget::slot_stop()
{
    m_time_hrs = 0;
    m_time_mins = 0;
    m_time_secs = -1;
    slot_update();
    slot_pause();
    std::cout << "stop" << std::endl;
}

void Widget::slot_update()
{
    // update the text
    if (is_paused)
        return;
    m_time_secs += 1;
    if (m_time_secs == 60)
    {
        m_time_mins += 1;
        m_time_secs = 0;
    }
    if (m_time_mins == 60)
    {
        m_time_hrs += 1;
        m_time_mins = 0;
    }
    QString hr = m_time_hrs >= 10 ? QString::number(m_time_hrs) : "0" + QString::number(m_time_hrs);
    QString min = m_time_mins >= 10 ? QString::number(m_time_mins) : "0" + QString::number(m_time_mins);
    QString sec = m_time_secs >= 10 ? QString::number(m_time_secs) : "0" + QString::number(m_time_secs);


    ui->time->setText( hr + ":" + min + ":" + sec);
}

Widget::~Widget()
{
    delete ui;
}
