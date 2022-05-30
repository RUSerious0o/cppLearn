#ifndef MYGPAPHICSVIEW_H
#define MYGPAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QAbstractGraphicsShapeItem>
#include <QColor>

#include <vector>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr);
    ~MyGraphicsView();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    enum ItemType { Rectangle, Ellipse, Star, ItemTypesCount };

private:
    QGraphicsScene *scene;
    ItemType currentItemType;
    QGraphicsItem *draggedItem;
    qreal initialX, initialY;
    bool rotationRequested;

    const double SZ = 100;
    std::vector<QColor> colors { Qt::yellow, Qt::blue, Qt::green, Qt::cyan, Qt::red, Qt::magenta };

    QAbstractGraphicsShapeItem* getNewGraphicsItem(qreal x, qreal y);
    void nextItemType();
};

#endif // MYGPAPHICSVIEW_H
