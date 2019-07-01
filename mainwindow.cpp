#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::showDialog(bool isOpen = true, int filterType = 0) {
    QString curPath = QDir::currentPath();
    QString dlgTitle = isOpen? "Open": "Save As";
    QString filter = "";
    if (filterType == 1) filter = "Desktop Entry (*.desktop)";
    if (filterType == 2) filter = "Icon (*.jpg *.bmp *.png *.svg)";
    QString fileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    return fileName;
}

void MainWindow::on_btnExec_clicked()
{
    QString fileName = this->showDialog();
    if (!fileName.isEmpty()) ui->editExec->setText(fileName);
}

void MainWindow::on_btnIcon_clicked()
{
    QString fileName = this->showDialog(true, 2);
    if (!fileName.isEmpty()) ui->editIcon->setText(fileName);
}
