// Silvia Orube Lopez

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QTextEdit>

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

private:
    Ui::MainWindow *ui;
    QTextEdit* textEdit;

};

#endif // MAINWINDOW_H
