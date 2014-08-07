#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = 0);
signals:
    void mousedata(int x,int y);
    void MouseClick(bool a);
public slots:
    void ReceiveData(int width,int height);

protected:
    void mousePressEvent(QMouseEvent *e);
private:
    QLabel mouseinfo;
};

#endif // MAPWIDGET_H
