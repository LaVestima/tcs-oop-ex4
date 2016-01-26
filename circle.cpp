#include "circle.h"

void Circle::setRadius(unsigned int r) {
    radius = r;
}

void Circle::draw(QPixmap *pixmap) {
    QPainter *painter = new QPainter(pixmap);
//    painter->setPen(QPen(color));
    painter->setPen(*(new QColor(225, 34, 255, 255)));
    painter->drawEllipse(100, 100, 100, 100);
//    painter->drawEllipse(p0.x(), p0.y(), radius/2, radius/2);
}

Circle::Circle(QPoint p) {

}
