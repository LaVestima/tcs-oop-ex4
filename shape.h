#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QPoint>

class Shape {
protected:
    QColor color;
    QPoint p0;
public:
    Shape() : color(Qt::black), p0(100, 100) {}
    Shape(QColor c) {color = c;}
    void setColor(const QColor &);
    void setOrigin(QPoint);
};

#endif // SHAPE_H
