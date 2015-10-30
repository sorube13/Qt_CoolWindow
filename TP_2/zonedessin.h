// Silvia Orube Lopez

#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>
#include <QPen>
#include <QList>
#include <QPoint>
#include <QVector>
#include <QMap>

namespace Ui {
class ZoneDessin;
}

class ZoneDessin : public QWidget
{
    Q_OBJECT

public:
    explicit ZoneDessin(QWidget *parent = 0);
    QList<QPainterPath> savePath();
    QMap<int, QPen> savePen();
    void loadPath(QList<QPainterPath>);
    void loadPen(QMap<int,QPen>);
    ~ZoneDessin();

private:
    Ui::ZoneDessin *ui;
    QPoint startPoint;
    QPoint endPoint;
    QList<QPainterPath > path;
    QMap<int, QPen> pen;
    QColor color;
    Qt::PenStyle style;
    int width;
    int draw;// 1-draw 0-choose
    int chosen; // Figure chosen from path[chosen]
    QPoint trans;

    //enum shape {LINE, RECT, ELLIPSE};
    int shape; // 1 - line, 2 - rect, 3 - ellipse


protected:
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    virtual void paintEvent(QPaintEvent*);

public slots:
    void colorLine();
    void penPoint(int);
    void penLine(int);
    void clearAll();
    void figureDraw(int);
    void changeMode(int);
    void undo();

private slots:
    void on_pushButton_clicked();
};


#endif // ZONEDESSIN_H
