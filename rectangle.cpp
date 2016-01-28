#include "rectangle.h"

Rectangle::Rectangle(QPoint p, int shapeWidth, int shapeHeight) {
    p0 = p;
    //width = 100;
    //height = 50;
    width = shapeWidth;
    height = shapeHeight;

    painter = new QPainter;
}

void Rectangle::draw(QPixmap *pixmap) {
    painter->begin(pixmap);
    painter->setPen(*(new QColor(225, 0, 0, 255)));
    painter->drawRect(p0.x(), p0.y(), width, height);
    //painter->drawEllipse(p0.x(), p0.y(), radius/2, radius/2);
    painter->end();
}
