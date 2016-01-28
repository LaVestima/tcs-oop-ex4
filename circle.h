#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPixmap>
#include <QPainter>

#include "shape.h"

class Circle : public Shape {
private:
    int radius;
    QPainter *painter;
public:
    Circle() : Shape(Qt::black) {radius = 100;}
    Circle(QPoint);
    Circle(QPoint, int);
    void setRadius(unsigned int);
    void draw(QPixmap *);
};

#endif // CIRCLE_H
