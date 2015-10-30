// Silvia Orube Lopez

#include "zonedessin.h"
#include "ui_zonedessin.h"
#include <QMouseEvent>
#include <QPainter>
#include <iostream>
#include <QToolBar>
#include <QColor>
#include <QColorDialog>
#include <QRect>
#include <QSize>


ZoneDessin::ZoneDessin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZoneDessin)
{
    //ui->setupUi(this);
    setMinimumSize(300,300);
    shape = 1; // 1-Line 2-Rectangle 3-Ellipse
    color = "black";
    width = 0; //Default color
    style = Qt::SolidLine;
    draw = 1; // draw by default 0-Edit figures
    chosen = -1;
}

ZoneDessin::~ZoneDessin()
{
    delete ui;
}

void ZoneDessin::mousePressEvent(QMouseEvent* e)
{
    if(draw == 0){
        QRect *zone = new QRect(e->pos(), *new QSize(10,10));
        zone->moveCenter(e->pos());
        for(int i=0; i<path.size(); i++){
            if(path[i].intersects(*zone)){
                chosen = i;
                trans.setX(e->pos().x());
                trans.setY(e->pos().y());
                break;
            }

        }
    }else{
        if (e-> button() == Qt::LeftButton){
            QPainterPath *p;
            QRectF *rect;
            startPoint = e->pos();
            endPoint = startPoint;
            switch(shape){
                case 1:
                    p = new QPainterPath(startPoint);
                    p->lineTo(endPoint);
                    path.append(*p);
                    break;
                   // path.append(p);
                case 2:
                    p = new QPainterPath();
                    rect = new QRectF(startPoint, endPoint);
                    p->addRect(*rect);
                    path.append(*p);
                    break;
                case 3:
                    p = new QPainterPath();
                    rect = new QRectF(startPoint, endPoint);
                    p->addEllipse(*rect);
                    path.append(*p);
                    break;
            }
            QPen *pn = new QPen(color, width, style);
            if(pen.size()==0){
                pen.insert(0, *pn);
            }else if(pen.size() < path.size()){
                pen.insert(path.size()-1, *pn);
            }
        }
        update();
    }
}

void ZoneDessin::mouseReleaseEvent(QMouseEvent* e){
    if(draw == 1){
        if((e->button() & Qt::LeftButton)){
            endPoint = e->pos();
            QPainterPath *p;
            QRectF *rect;
            switch(shape){
                case 1:
                    p = new QPainterPath(startPoint);
                    p->lineTo(endPoint);
                    path[path.size()-1]= *p;
                    break;
                case 2:
                    p = new QPainterPath();
                    rect = new QRectF(startPoint, endPoint);
                    p->addRect(*rect);
                    path[path.size()-1]= *p;
                    break;
                case 3:
                    p = new QPainterPath();
                    rect = new QRectF(startPoint, endPoint);
                    p->addEllipse(*rect);
                    path[path.size()-1]= *p;
                    break;
            }

            update();
        }
    }else if (chosen != -1){
        path[chosen].moveTo(e->pos());
    }
}

void ZoneDessin::mouseMoveEvent(QMouseEvent *e){
    if(draw == 1){
        if(e->buttons() & Qt::LeftButton) {
            endPoint = e-> pos();
            QPainterPath *p;
            QRectF *rect;
            switch(shape){
                case 1:
                    p = new QPainterPath(startPoint);
                    p->lineTo(endPoint);
                    path[path.size()-1]= *p;
                    break;
                case 2:
                    p = new QPainterPath();
                    rect = new QRectF(startPoint, endPoint);
                    p->addRect(*rect);
                    path[path.size()-1]= *p;
                    break;
                case 3:
                    p = new QPainterPath();
                    rect = new QRectF(startPoint, endPoint);
                    p->addEllipse(*rect);
                    path[path.size()-1]= *p;
                    break;
            }
        }
        update();
    }else if(chosen != -1){
        path[chosen].translate((e->pos().x()-trans.x()),(e->pos().y()-trans.y()));
        trans = e->pos();
        update();
    }
}

void ZoneDessin::colorLine(){
    QPen *p;
    if((draw == 0) && (chosen!= -1)){
        QColor color_c = QColorDialog::getColor();
        Qt::PenStyle style1 = pen[chosen].style();
        int width1 = pen[chosen].width();
        p = new QPen(color_c, width1, style1);
        pen.insert(chosen, *p);
        update();
    }else{
        color = QColorDialog::getColor();
        p = new QPen(color, width, style);
        if(pen.size()==0){
            pen.insert(0, *p);
        }else{
            pen.insert(path.size(), *p);

        }
    }
    delete p;
}


void ZoneDessin::penPoint(int value){
    QPen *p;
    if((draw == 0) && (chosen!= -1)){
        int width1;
        switch(value){
            case 1:
                width1 = 0;
                break;
            case 2:
                width1 = 8;
                break;
            case 3:
                width1 = 15;
                break;
        }
        QColor color1 = pen[chosen].color();
        Qt::PenStyle style1 = pen[chosen].style();
        p = new QPen(color1, width1, style1);
        pen.insert(chosen, *p);
        update();
    }else{
        switch(value){
            case 1:
                width = 0;
                break;
            case 2:
                width = 8;
                break;
            case 3:
                width = 15;
                break;
        }

        p = new QPen(color, width, style);
        if(pen.size()==0){
            pen.insert(0, *p);
        }else{
            pen.insert(path.size(), *p);
        }
    }
    delete p;
}


void ZoneDessin::penLine(int value){
    QPen *p;
    if((draw == 0) && (chosen!= -1)){
        QColor color1 = pen[chosen].color();
        int width1 = pen[chosen].width();
        Qt::PenStyle style1;
        switch(value){
            case 1:
                style1 = Qt::SolidLine;
                break;
            case 2:
                style1 = Qt::DashLine;
                break;
            case 3:
                style1 = Qt::DotLine;
                break;
        }
        p = new QPen(color1, width1, style1);
        pen.insert(chosen, *p);
        update();
    }else{
        switch(value){
            case 1:
                style = Qt::SolidLine;
                break;
            case 2:
                style = Qt::DashLine;
                break;
            case 3:
                style = Qt::DotLine;
                break;
        }
        p = new QPen(color, width, style);
        if(pen.size()==0){
            pen.insert(0, *p);
        }else{
            pen.insert(path.size(), *p);
        }
    }
    delete p;
}

void ZoneDessin::clearAll(){
    path.clear();
    pen.clear();
    /* Default values (uncomment to reset when clear)
    shape = 1;
    color = "black";
    width = 0;
    style = Qt::SolidLine;*/
    chosen = -1;
    draw = 1;
    update();
}

void ZoneDessin::changeMode(int value){
    switch(value){
        case 1:
            draw = 1;
            break;
        case 2:
            draw = 0;
            break;
    }
}

void ZoneDessin::figureDraw(int value){
    switch(value){
        case 1:
            shape = 1;
            break;
        case 2:
            shape = 2;
            break;
        case 3:
            shape = 3;
            break;
    }
}

void ZoneDessin::paintEvent(QPaintEvent *e){
    QWidget::paintEvent(e);
    QPainter painter(this);
    for(int i=0; i<path.size(); i++){
        painter.setPen(pen[i]);
        painter.drawPath(path[i]);
    }
}





QList<QPainterPath> ZoneDessin::savePath(){
    return path;
}

QMap<int,QPen> ZoneDessin::savePen(){
    return pen;
}

void ZoneDessin::loadPath(QList<QPainterPath> p){
    path.clear();
    path = p;
    update();
}

void ZoneDessin::loadPen(QMap<int, QPen> p){
    pen.clear();
    pen = p;
    update();
}

void ZoneDessin::undo(){
    if(!path.isEmpty()){
        pen.remove(path.size()-1);
        path.removeLast();
        update();
    }
}

void ZoneDessin::on_pushButton_clicked()
{
    std::cout << "Button was pushed!" << std::endl;
}
