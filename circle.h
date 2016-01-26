#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPixmap>
#include <QPainter>

#include "shape.h"

class Circle : public Shape {
private:
    unsigned int radius;
public:
    Circle() : Shape(Qt::black) {radius = 100;}
    Circle(QPoint);
    void setRadius(unsigned int);
    void draw(QPixmap *);
};

#endif // CIRCLE_H
