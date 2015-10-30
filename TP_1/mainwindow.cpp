// Silvia Orube Lopez

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <iostream>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>
#include <QCloseEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMenuBar* menuBar = this->menuBar();
    QMenu* fileMenu = menuBar->addMenu(tr("&File"));
    QToolBar* toolBar = this->addToolBar(tr("&File"));
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    statusBar();

    QAction* openAction = new QAction(QIcon(":images/open.png"), tr("&Open..."), this);
    QAction* saveAction = new QAction(QIcon(":images/save.png"), tr("&Save..."), this);
    QAction* quitAction = new QAction(QIcon(":images/quit.png"), tr("&Quit..."), this);

    openAction->setShortcut(tr("Ctrl+O"));
    saveAction->setShortcut(tr("Ctrl+S"));
    quitAction->setShortcut(tr("Ctrl+Q"));

    openAction->setToolTip(tr("Open File"));
    saveAction->setToolTip(tr("Save File"));
    quitAction->setToolTip(tr("Quit"));

    openAction->setStatusTip(tr("Open File"));
    saveAction->setStatusTip(tr("Save File"));
    quitAction->setStatusTip(tr("Quit"));

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);

    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(quitAction);



    QObject::connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));
    QObject::connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));
    QObject::connect(quitAction,SIGNAL(triggered()),this,SLOT(quitApp()));

    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Text"),
                                                    QString());

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString line = stream.readAll();
    textEdit->setHtml(line);
    file.close();

    std::cout << qPrintable(line) << std::endl;
}

void MainWindow::saveFile()
{
    QString text = textEdit->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Open Text"));
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);
        stream << text << endl;
    }
    std::cout << qPrintable(fileName) << std::endl;
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
    reply = QMessageBox::question(this, "TP_1", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          QApplication::quit();
      }else{
          event->ignore();
      }
 }
