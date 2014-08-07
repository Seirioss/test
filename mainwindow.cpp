#include "mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralWidget->setFixedSize(1200,700);
    //ui->widget_map->setStyle();
    ui->ID->setEnabled(false);
    ui->Map->setEnabled(false);
    ui->Major->setEnabled(false);
    ui->PointID->setEnabled(false);
    QImage* image=new QImage;
    connect(ui->MapIn,SIGNAL(clicked()),this,SLOT(on_slotOpenImage_triggered()));
    connect(ui->widget_map,SIGNAL(mousedata(int,int)),this,SLOT(slot_mousereceive(int,int)));
    connect(ui->widget_map,SIGNAL(MouseClick(bool)),this,SLOT(slot_MouseClick(bool)));
    connect(this,SIGNAL(SendData(int,int)),ui->widget_map,SLOT(ReceiveData(int,int)));
}

void MainWindow::on_slotOpenImage_triggered()
{
    QString filename;
        filename=QFileDialog::getOpenFileName(this,tr("选择图像"),"",tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
        if(filename.isEmpty())
        {
             return;
        }
        else
        {
            ui->widget_map->setAutoFillBackground(true);
            QPalette palette;
            palette.setBrush(QPalette::Background, QBrush(QPixmap(filename).scaled(ui->widget_map->size())));
            ui->widget_map->setPalette(palette);
        }
        MapWidth=QPixmap(filename).width();
        MapHeight=QPixmap(filename).height();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_load_clicked()
{
    QSqlQuery qry;
    qry.prepare( "INSERT INTO names (ID, Map, Major, PointID, X, Y) VALUES (:ID,:Map,:Major,:PointID,:X,:Y)" );
    qry.bindValue(0,ui->ID->text());
    qry.bindValue(1,ui->Map->text());
    qry.bindValue(2,ui->Major->text());
    qry.bindValue(3,ui->PointID->text());
    qry.bindValue(4,ui->X->text());
    qry.bindValue(5,ui->Y->text());
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
      qDebug( "Inserted!" );
    ui->ID->setEnabled(false);
    ui->Map->setEnabled(false);
    ui->Major->setEnabled(false);
    ui->PointID->setEnabled(false);
}

void MainWindow::on_MapIn_clicked()
{
    DB::CreateDataBase();
    ui->ID->setEnabled(false);
    ui->Map->setEnabled(false);
    ui->Major->setEnabled(false);
    ui->PointID->setEnabled(false);
}

void MainWindow::on_DataOut_clicked()
{
    DB::DataOutput();
}

void MainWindow::slot_mousereceive(int x, int y)
{   float h=MapWidth/630;
    float v=MapHeight/610;
    int width=x*h;
    int height=y*v;
    ui->X->setText(QString::number(width));
    ui->Y->setText(QString::number(height));

    emit SendData(width,height);
}

void MainWindow::slot_MouseClick(bool a)
{
    if(a){
        ui->ID->setEnabled(true);
        ui->Map->setEnabled(true);
        ui->Major->setEnabled(true);
        ui->PointID->setEnabled(true);
    }
}







