#include "triangle.h"

Triangle::Triangle(QPoint p) {
    p0 = p;
    width = 100;
    height = 50;

    painter = new QPainter;
}

void Triangle::draw(QPixmap *pixmap) {
    painter->begin(pixmap);
    painter->setPen(*(new QColor(225, 0, 0, 255)));
    painter->drawLine(p0.x()+width/2, p0.y(), p0.x()+width, p0.y()+height);
    painter->drawLine(p0.x()+width, p0.y()+height, p0.x(), p0.y()+height);
    painter->drawLine(p0.x(), p0.y()+height, p0.x()+width/2, p0.y());
//    painter->drawRect(p0.x(), p0.y(), width, height);
    //painter->drawEllipse(p0.x(), p0.y(), radius/2, radius/2);
    painter->end();
}
