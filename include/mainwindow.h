#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QFrame>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsItem>
#include <QLineEdit>
#include <QMap>
#include <QMouseEvent> // Include the necessary header for QMouseEvent
#include "../include/circleitem.h"
#include "../include/arrowitem.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *leftWidget; // The left QFrame
    QWidget *rightWidget; // The right QFrame
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsEllipseItem *selectedCircle1 = nullptr;
    QGraphicsEllipseItem *selectedCircle2 = nullptr;
    QList<CircleItem*> circles;
    QTimer *timer;
    QMap<QGraphicsEllipseItem*, QList<QGraphicsEllipseItem*>> arrows;
    QList<ArrowItem*> drawnArrows;
    QLineEdit *valueLabel;
    ArrowItem * selectedArrow;
    bool isCircleSelected = false;
    bool ascendingSelection=true;
    void deleteSelectedItems();
    void handleSelectionChanged();
    void handleRefresh();
    bool checkSelected();
protected:
    bool eventFilter(QObject *watched, QEvent *event); // Declare eventFilter function

private slots:
    void on_updateButton_clicked();
};

#endif // MAINWINDOW_H
