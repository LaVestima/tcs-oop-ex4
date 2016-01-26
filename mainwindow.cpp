#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    pixmap = new QPixmap(300, 300);

    ui->label->installEventFilter(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event) {
    if(object == ui->label) { //check if the event was emitted from QLabel component
        if(event->type() == QEvent::MouseButtonDblClick) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            circleList.push_back(Circle(mouseEvent->pos()));
            //shapeList.push_back(Circle(mouseEvent->pos())); // position of
                //the shape should be passed by the constructor


            ui->comboBox->addItem(QString::number(circleList.count()-1));

            //circleList[0].draw(pixmap);

            //ui->label_4->setText(QString::);
            // here some ‘drawing the shapes’ method should be invoked
        }
    }
    return QMainWindow::eventFilter(object,event); // parent method is invoked
}

void MainWindow::on_drawPushButton_clicked() {
    pixmap->fill(); //pixmap is a QPixmap object
    for(int i = 0; i < circleList.count(); i++) {
        circleList[i].draw(pixmap); // circles is QList<Circle> object
    }
    ui->label->setPixmap(*pixmap); // the QPixmap object is being
    // associated with QLabel component
}
