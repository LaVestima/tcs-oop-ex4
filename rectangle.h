#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPixmap>
#include <QPainter>

#include "shape.h"

class Rectangle : public Shape {
private:
    int width;
    int height;
    QPainter *painter;
public:
    Rectangle(QPoint);
    Rectangle(QPoint, int, int);
    void draw(QPixmap *);
};

#endif // RECTANGLE_H
