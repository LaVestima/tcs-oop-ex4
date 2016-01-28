#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    pixmap = new QPixmap(ui->label->width(), ui->label->height());

    ui->label->installEventFilter(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event) { // Double click event
    if(object == ui->label) {
        if(event->type() == QEvent::MouseButtonDblClick) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

            for (int i = 0; i < 3; i++) {
                QRadioButton* shapeButton = findChild<QRadioButton*>("radioButton_" + QString::number(i));

                if (shapeButton->isChecked()) {
                    switch(i) {
                    case 0: // Circle
                        circleList.push_back(Circle(mouseEvent->pos()));
                        ui->circleComboBox->addItem(QString::number(circleList.count()-1));
                        ui->circleComboBox->setCurrentIndex(-1);
                        break;
                    case 1: // Rectangle
                        rectangleList.push_back(Rectangle(mouseEvent->pos()));
                        ui->rectangleComboBox->addItem(QString::number(rectangleList.count()-1));
                        ui->rectangleComboBox->setCurrentIndex(-1);
                        break;
                    case 2: // Triangle
                        triangleList.push_back(Triangle(mouseEvent->pos()));
                        ui->triangleComboBox->addItem(QString::number(triangleList.count()-1));
                        ui->triangleComboBox->setCurrentIndex(-1);
                        break;
                    }
                }
            }
        }
    }
    return QMainWindow::eventFilter(object,event);
}

void MainWindow::on_drawPushButton_clicked() {
    pixmap->fill(Qt::white);

    if (ui->checkBox->isChecked()) {
        for(int i = 0; i < circleList.count(); i++) {
            circleList[i].draw(pixmap);
        }
        for(int i = 0; i < rectangleList.count(); i++) {
            rectangleList[i].draw(pixmap);
        }
        for(int i = 0; i < triangleList.count(); i++) {
            triangleList[i].draw(pixmap);
        }
    }
    else {
        int shapeNumber = -1;
        if ((shapeNumber = ui->circleComboBox->currentIndex()) >= 0) {
            circleList[shapeNumber].draw(pixmap);
        }
        else if ((shapeNumber = ui->rectangleComboBox->currentIndex()) >= 0) {
            rectangleList[shapeNumber].draw(pixmap);
        }
        else if ((shapeNumber = ui->triangleComboBox->currentIndex()) >= 0) {
            triangleList[shapeNumber].draw(pixmap);
        }

    }

    ui->label->setPixmap(*pixmap);
}

void MainWindow::on_circleComboBox_currentIndexChanged(int index) {
    ui->rectangleComboBox->setCurrentIndex(-1);
    ui->triangleComboBox->setCurrentIndex(-1);
    ui->checkBox->setChecked(false);
    ui->circleComboBox->setCurrentIndex(index);
}

void MainWindow::on_rectangleComboBox_currentIndexChanged(int index) {
    ui->circleComboBox->setCurrentIndex(-1);
    ui->triangleComboBox->setCurrentIndex(-1);
    ui->checkBox->setChecked(false);
    ui->rectangleComboBox->setCurrentIndex(index);
}

void MainWindow::on_triangleComboBox_currentIndexChanged(int index) {
    ui->circleComboBox->setCurrentIndex(-1);
    ui->rectangleComboBox->setCurrentIndex(-1);
    ui->checkBox->setChecked(false);
    ui->triangleComboBox->setCurrentIndex(index);
}

void MainWindow::on_deleteSelectedPushButton_clicked() {
    int shapeNumber = -1;
    if ((shapeNumber = ui->circleComboBox->currentIndex()) >= 0) {
        circleList.removeAt(shapeNumber);
        ui->circleComboBox->removeItem(circleList.count());
    }
    else if ((shapeNumber = ui->rectangleComboBox->currentIndex()) >= 0) {
        rectangleList.removeAt(shapeNumber);
        ui->rectangleComboBox->removeItem(rectangleList.count());
    }
    else if ((shapeNumber = ui->triangleComboBox->currentIndex()) >= 0) {
        triangleList.removeAt(shapeNumber);
        ui->triangleComboBox->removeItem(triangleList.count());
    }
}

void MainWindow::on_deleteAllPushButton_clicked() {
    for(int i = 0; i < circleList.count(); i++) {
        ui->circleComboBox->removeItem(0);
    }
    circleList.clear();
    for(int i = 0; i < rectangleList.count(); i++) {
        ui->rectangleComboBox->removeItem(0);
    }
    rectangleList.clear();
    for(int i = 0; i < triangleList.count(); i++) {
        ui->triangleComboBox->removeItem(0);
    }
    triangleList.clear();
}
