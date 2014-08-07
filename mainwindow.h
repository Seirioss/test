
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QMouseEvent>
#include <QPalette>
#include <QPixmap>
#include "db.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void SendData(int width,int height);

private slots:
    void on_MapIn_clicked();
    void on_slotOpenImage_triggered();

    void on_load_clicked();

    void on_DataOut_clicked();

    void slot_mousereceive(int x, int y);

    void slot_MouseClick(bool a);

private:
    Ui::MainWindow *ui;
    float MapWidth;
    float MapHeight;

};

#endif // MAINWINDOW_H
