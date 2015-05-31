#include "MapEditWindow.hpp"
#include "ui_MapEditWindow.h"

#include <QApplication>
#include <QString>
#include <QFileDialog>

MapEditWindow::MapEditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapEditWindow)
{
    ui->setupUi(this);
    connect(ui->actionNew,SIGNAL(triggered()),this, SLOT(newClicked()));
    connect(ui->actionOpen,SIGNAL(triggered()), this, SLOT(openClicked()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveClicked()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAsClicked()));
    connect(ui->actionDraw_Grid, SIGNAL(toggled(bool)), ui->wdgMapEdit, SLOT(toggle_grid(bool)));
    connect(this,SIGNAL(newMap()),ui->wdgMapEdit, SLOT(clearMap()));
    connect(this,SIGNAL(mapChanged(QString)), ui->wdgMapEdit, SLOT(newMapFile(QString)));
    map = nullptr;
}

MapEditWindow::~MapEditWindow()
{
    delete ui;
}

void MapEditWindow::newClicked() {
    emit this->newMap();
}

void MapEditWindow::openClicked() {
    QFileDialog dlg;
    QString filename = dlg.getOpenFileName(this,"Open Map File", qApp->applicationDirPath(),"*.map");
    emit this->mapChanged(filename);
}

void MapEditWindow::saveClicked() {
    MutableMap* m = ui->wdgMapEdit->getMap();
    QString f = m->getFilename();
    QFileDialog dlg;
    if(f.length()<=0) {
        f = dlg.getSaveFileName(this,"Save Map File", qApp->applicationDirPath(), "*.map");
    }
    if(f.length()>=5) {
        m->saveToFile(f);
    }
}

void MapEditWindow::saveAsClicked() {
    MutableMap* m = ui->wdgMapEdit->getMap();
    QFileDialog dlg;
    QString f = dlg.getSaveFileName(this, "Save Map File", qApp->applicationDirPath(), "*.map");
    if(f.length()>=5) {
        m->saveToFile(f);
    }
}
