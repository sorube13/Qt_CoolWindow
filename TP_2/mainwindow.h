// Silvia Orube Lopez

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QTextEdit>
#include "zonedessin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
     void closeEvent(QCloseEvent *event);

public slots:
    void openFile();
    void saveFile();
    void quitApp();

private slots:



    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionQuit_triggered();

    void on_actionClear_triggered();

    void on_actionColor_triggered();

    void on_actionSmall_Point_triggered();

    void on_actionBig_Point_triggered();

    void on_actionMedium_Point_triggered();

    void on_actionLine_triggered();

    void on_actionDraw_triggered();

    void on_actionEdit_triggered();

    void on_actionRectangle_triggered();

    void on_actionEllipse_triggered();

    void on_actionSolidLine_triggered();

    void on_actionDashLine_triggered();

    void on_actionDotLine_triggered();

    void on_actionUndo_triggered();

private:
    Ui::MainWindow *ui;
    ZoneDessin* dessinEdit;

};

#endif // MAINWINDOW_H
