#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPixmap>
#include <QPainter>

#include "shape.h"

class Triangle : public Shape {
private:
    int width;
    int height;
    QPainter *painter;
public:
    Triangle(QPoint);
    void draw(QPixmap *);
};

#endif // TRIANGLE_H
