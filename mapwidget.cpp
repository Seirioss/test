#include "mapwidget.h"
#include <QDebug>

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent)
{
    mouseinfo.setParent(this);
}

void MapWidget::ReceiveData(int width, int height)
{
    mouseinfo.setText("("+QString::number(width)+","+QString::number(height)+")");
    mouseinfo.show();
}


void MapWidget::mousePressEvent(QMouseEvent *e)
{
    mouseinfo.resize(70,25);
    mouseinfo.move(e->x(),e->y());
    emit mousedata(e->x(),e->y());
    emit MouseClick(true);
}
