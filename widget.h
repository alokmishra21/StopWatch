#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer *m_timer;
    unsigned int m_time_secs;
    unsigned int m_time_mins;
    unsigned int m_time_hrs;
    bool is_paused;

public slots:
    void slot_stop();
    void slot_pause();
    void slot_play();
    void slot_update();
};

#endif // WIDGET_H
