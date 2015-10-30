// Silvia Orube Lopez

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zonedessin.h"
#include <QTextEdit>
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>
#include <QCloseEvent>
#include <QColorDialog>
#include <QSignalMapper>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//    QMenuBar* menuBar = this->menuBar();
//    QMenu* fileMenu = menuBar->addMenu(tr("&File"));
//    QMenu* penMenu = menuBar->addMenu(tr("&Pen"));
//    QMenu* figureMenu = menuBar->addMenu(tr("&Figure"));
//    QMenu* modeMenu = menuBar->addMenu(tr("&Mode"));
//    QToolBar* toolBar = this->addToolBar(tr("&File"));
//    QToolBar* dessinToolBar = this->addToolBar(tr("&Pen"));
//    QToolBar* figureToolBar = this->addToolBar(tr("&Figure"));
    dessinEdit = new ZoneDessin(this);
    setCentralWidget(dessinEdit);

    statusBar();

//    QAction* openAction = new QAction(QIcon(":images/open.png"), tr("&Open..."), this);
//    QAction* saveAction = new QAction(QIcon(":images/save.png"), tr("&Save..."), this);
//    QAction* quitAction = new QAction(QIcon(":images/quit.png"), tr("&Quit..."), this);

//    openAction->setShortcut(tr("Ctrl+O"));
//    saveAction->setShortcut(tr("Ctrl+S"));
//    quitAction->setShortcut(tr("Ctrl+Q"));

//    openAction->setToolTip(tr("Open File"));
//    saveAction->setToolTip(tr("Save File"));
//    quitAction->setToolTip(tr("Quit"));

//    openAction->setStatusTip(tr("Open File"));
//    saveAction->setStatusTip(tr("Save File"));
//    quitAction->setStatusTip(tr("Quit"));

//    fileMenu->addAction(openAction);
//    fileMenu->addAction(saveAction);
//    fileMenu->addAction(quitAction);

//    toolBar->addAction(openAction);
//    toolBar->addAction(saveAction);
//    toolBar->addAction(quitAction);

//    QObject::connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));
//    QObject::connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));
//    QObject::connect(quitAction,SIGNAL(triggered()),this,SLOT(quitApp()));

//    QAction* colorAction = new QAction(QIcon(":images/color.png"), tr("&Color"), this);
//    colorAction->setShortcut(tr("Ctrl+C"));
//    colorAction->setToolTip(tr("Set color"));
//    colorAction->setStatusTip(tr("Set color"));

//    QAction* width1Action = new QAction(QIcon(":images/smallPoint.png"), tr("&small point"), this);
//    width1Action->setShortcut(tr("Ctrl+1"));
//    width1Action->setToolTip(tr("Small Point"));
//    width1Action->setStatusTip(tr("Small Point"));

//    QAction* width2Action = new QAction(QIcon(":images/mediumPoint.png"), tr("&medium point"), this);
//    width2Action->setShortcut(tr("Ctrl+2"));
//    width2Action->setToolTip(tr("Medium Point"));
//    width2Action->setStatusTip(tr("Medium Point"));

//    QAction* width3Action = new QAction(QIcon(":images/bigPoint.png"), tr("&big point"), this);
//    width3Action->setShortcut(tr("Ctrl+3"));
//    width3Action->setToolTip(tr("Big Point"));
//    width3Action->setStatusTip(tr("Big Point"));

//    QAction* solidAction = new QAction(QIcon(":images/solidLine.png"), tr("&solid line"), this);
//    solidAction->setShortcut(tr("Ctrl+4"));
//    solidAction->setToolTip(tr("Solid Line"));
//    solidAction->setStatusTip(tr("Solid Line"));

//    QAction* dashAction = new QAction(QIcon(":images/dashLine.png"), tr("&dash line"), this);
//    dashAction->setShortcut(tr("Ctrl+5"));
//    dashAction->setToolTip(tr("Dash Line"));
//    dashAction->setStatusTip(tr("Dash Line"));

//    QAction* dotAction = new QAction(QIcon(":images/dotLine.png"), tr("&dot line"), this);
//    dotAction->setShortcut(tr("Ctrl+6"));
//    dotAction->setToolTip(tr("Dot Line"));
//    dotAction->setStatusTip(tr("Dot Line"));

//    QAction* clearAction = new QAction(QIcon(":images/clear.jpg"), tr("&clear"), this);
//    clearAction->setShortcut(tr("Ctrl+C"));
//    clearAction->setToolTip(tr("Clear"));
//    clearAction->setStatusTip(tr("Clear"));

//    dessinToolBar->addAction(colorAction);
//    dessinToolBar->addAction(width1Action);
//    dessinToolBar->addAction(width2Action);
//    dessinToolBar->addAction(width3Action);
//    dessinToolBar->addAction(solidAction);
//    dessinToolBar->addAction(dashAction);
//    dessinToolBar->addAction(dotAction);
//    dessinToolBar->addAction(clearAction);
//    penMenu->addAction(colorAction);
//    penMenu->addAction(width1Action);
//    penMenu->addAction(width2Action);
//    penMenu->addAction(width3Action);
//    penMenu->addAction(solidAction);
//    penMenu->addAction(dashAction);
//    penMenu->addAction(dotAction);
//    penMenu->addAction(clearAction);


//    QAction* lineAction = new QAction(QIcon(":images/solidLine.png"), tr("&Line"), this);
//    lineAction->setShortcut(tr("Ctrl+L"));
//    lineAction->setToolTip(tr("Line"));
//    lineAction->setStatusTip(tr("Line"));

//    QAction* rectAction = new QAction(QIcon(":images/rectangle.png"), tr("&Rectangle"), this);
//    rectAction->setShortcut(tr("Ctrl+R"));
//    rectAction->setToolTip(tr("Rectangle"));
//    rectAction->setStatusTip(tr("Rectangle"));

//    QAction* ellipseAction = new QAction(QIcon(":images/ellipse.png"), tr("&Ellipse"), this);
//    ellipseAction->setShortcut(tr("Ctrl+P"));
//    ellipseAction->setToolTip(tr("Ellipse"));
//    ellipseAction->setStatusTip(tr("Ellipse"));

//    figureMenu->addAction(lineAction);
//    figureMenu->addAction(rectAction);
//    figureMenu->addAction(ellipseAction);
//    figureToolBar->addAction(lineAction);
//    figureToolBar->addAction(rectAction);
//    figureToolBar->addAction(ellipseAction);


//    QAction* drawAction = new QAction(tr("&Draw"), this);
//    drawAction->setShortcut(tr("Ctrl+D"));
//    drawAction->setToolTip(tr("Draw"));
//    drawAction->setStatusTip(tr("Draw"));

//    QAction* editAction = new QAction(tr("&Edit"), this);
//    editAction->setShortcut(tr("Ctrl+E"));
//    editAction->setToolTip(tr("Edit"));
//    editAction->setStatusTip(tr("Edit"));

//    modeMenu->addAction(drawAction);
//    modeMenu->addAction(editAction);

//    QAction* undoAction = new QAction(QIcon(":images/undo.png"), tr("&Undo..."), this);
//    undoAction->setShortcut(tr("Ctrl+Z"));
//    undoAction->setToolTip(tr("Undo"));
//    undoAction->setStatusTip(tr("Undo"));

//    fileMenu->addAction(undoAction);
//    toolBar->addAction(undoAction);


//    QObject::connect(colorAction,SIGNAL(triggered()), dessinEdit, SLOT(colorLine()));

//    QSignalMapper* mapper1 = new QSignalMapper(this);
//    connect(mapper1,SIGNAL(mapped(int)),dessinEdit,SLOT(penPoint(int)));

//    connect(width1Action,SIGNAL(triggered()), mapper1, SLOT(map()));
//    mapper1->setMapping(width1Action,1);
//    connect(width2Action,SIGNAL(triggered()), mapper1, SLOT(map()));
//    mapper1->setMapping(width2Action,2);
//    connect(width3Action,SIGNAL(triggered()), mapper1, SLOT(map()));
//    mapper1->setMapping(width3Action,3);

//    QSignalMapper* mapper2 = new QSignalMapper(this);
//    connect(mapper2,SIGNAL(mapped(int)),dessinEdit,SLOT(penLine(int)));

//    connect(solidAction,SIGNAL(triggered()), mapper2, SLOT(map()));
//    mapper2->setMapping(solidAction,1);
//    connect(dashAction,SIGNAL(triggered()), mapper2, SLOT(map()));
//    mapper2->setMapping(dashAction,2);
//    connect(dotAction,SIGNAL(triggered()), mapper2, SLOT(map()));
//    mapper2->setMapping(dotAction,3);

//    QObject::connect(clearAction,SIGNAL(triggered()), dessinEdit, SLOT(clearAll()));

//    QSignalMapper* mapper3 = new QSignalMapper(this);
//    connect(mapper3,SIGNAL(mapped(int)),dessinEdit,SLOT(figureDraw(int)));

//    connect(lineAction,SIGNAL(triggered()), mapper3, SLOT(map()));
//    mapper3->setMapping(lineAction,1);
//    connect(rectAction,SIGNAL(triggered()), mapper3, SLOT(map()));
//    mapper3->setMapping(rectAction,2);
//    connect(ellipseAction,SIGNAL(triggered()), mapper3, SLOT(map()));
//    mapper3->setMapping(ellipseAction,3);

//    QSignalMapper* mapper4 = new QSignalMapper(this);
//    connect(mapper4, SIGNAL(mapped(int)), dessinEdit, SLOT(changeMode(int)));

//    connect(drawAction,SIGNAL(triggered()), mapper4, SLOT(map()));
//    mapper4->setMapping(drawAction,1);
//    connect(editAction,SIGNAL(triggered()), mapper4, SLOT(map()));
//    mapper4->setMapping(editAction,2);

//    QObject::connect(undoAction,SIGNAL(triggered()), dessinEdit, SLOT(undo()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    try{
        QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Text"),
                                                    QString());
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);

        QList<QPainterPath> path;
        QMap<int,QPen> pen;

        in >> path >> pen;

        dessinEdit->loadPath(path);
        dessinEdit->loadPen(pen);
        file.close();
    }catch (std::exception & e){

    }
}

void MainWindow::saveFile()
{
    try{
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("Open Text"));
        QFile file(fileName);
        if (file.open(QIODevice::ReadWrite)){
            QList<QPainterPath> path = dessinEdit->savePath();
            QMap<int,QPen> pen = dessinEdit->savePen();
            QDataStream out(&file);
            out << path;
            out << pen;
            std::cout << "Saved" << std::endl;
        }
    }catch(std::exception & e){}

}

void MainWindow::quitApp()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        QApplication::quit();
      }
    std::cout << "quit App" << std::endl;
}

void MainWindow::closeEvent(QCloseEvent *event)
 {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "TP_2", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          QApplication::quit();
      }else{
          event->ignore();
      }
 }


void MainWindow::on_actionOpen_triggered()
{
    MainWindow::openFile();
}

void MainWindow::on_actionSave_triggered()
{
    MainWindow::saveFile();
}

void MainWindow::on_actionQuit_triggered()
{
    MainWindow::quitApp();
}

void MainWindow::on_actionClear_triggered()
{
    dessinEdit->clearAll();
}

void MainWindow::on_actionColor_triggered()
{
    dessinEdit->colorLine();
}

void MainWindow::on_actionSmall_Point_triggered()
{
    dessinEdit->penPoint(1);
}

void MainWindow::on_actionBig_Point_triggered()
{
    dessinEdit->penPoint(2);
}

void MainWindow::on_actionMedium_Point_triggered()
{
    dessinEdit->penPoint(3);
}

void MainWindow::on_actionLine_triggered()
{
    dessinEdit->figureDraw(1);
}

void MainWindow::on_actionRectangle_triggered()
{
    dessinEdit->figureDraw(2);
}

void MainWindow::on_actionEllipse_triggered()
{
    dessinEdit->figureDraw(3);
}

void MainWindow::on_actionDraw_triggered()
{
    dessinEdit->changeMode(1);
}

void MainWindow::on_actionEdit_triggered()
{
    dessinEdit->changeMode(2);
}

void MainWindow::on_actionSolidLine_triggered()
{
    dessinEdit->penLine(1);
}

void MainWindow::on_actionDashLine_triggered()
{
    dessinEdit->penLine(2);
}

void MainWindow::on_actionDotLine_triggered()
{
    dessinEdit->penLine(3);
}

void MainWindow::on_actionUndo_triggered()
{
    dessinEdit->undo();
}
