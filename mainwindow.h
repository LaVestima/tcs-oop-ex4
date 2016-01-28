#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QEvent>
#include <QMouseEvent>
#include <QPixmap>

#include <shape.h>
#include <circle.h>
#include <rectangle.h>
#include <triangle.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QPixmap *pixmap;
    QList<Shape> shapeList;
    QList<Circle> circleList;
    QList<Rectangle> rectangleList;
    QList<Triangle> triangleList;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *, QEvent *);

private slots:
    void on_drawPushButton_clicked();
    void on_circleComboBox_currentIndexChanged(int index);
    void on_rectangleComboBox_currentIndexChanged(int index);
    void on_triangleComboBox_currentIndexChanged(int index);
    void on_deleteSelectedPushButton_clicked();
    void on_deleteAllPushButton_clicked();
};

#endif // MAINWINDOW_H
