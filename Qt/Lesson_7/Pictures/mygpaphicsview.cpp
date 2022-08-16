#include "mygpaphicsview.h"

#include <QGraphicsView>
#include <QMouseEvent>
#include <QBrush>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include <QAbstractGraphicsShapeItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QtMath>

#include <cmath>
#include <cstdint>
#include <ctime>

MyGraphicsView::MyGraphicsView(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene(this)),
    currentItemType(Rectangle),
    draggedItem(nullptr),
    rotationRequested(false)
{
    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setBackgroundBrush({Qt::black});

    srand(time(0));
}

MyGraphicsView::~MyGraphicsView() { }

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        if(scene->itemAt(event->x(), event->y(), QTransform()) != 0) {
            draggedItem = scene->itemAt(event->x(), event->y(), QTransform());            
            initialX = event->pos().x() - draggedItem->x();
            initialY = event->pos().y() - draggedItem->y();
        } else {
            bool collidesWithOther = false;
            QGraphicsItem *newItem = getNewGraphicsItem(event->x(), event->y());

            if(scene->items().count() > 0) {
                for(QGraphicsItem *item : scene->items()) {
                    if(item->collidesWithItem(newItem)) {
                        collidesWithOther = true;
                        break;
                    }
                }
            }

            if(!collidesWithOther) {
                scene->addItem(newItem);
                nextItemType();
            }
        }
    }

    if(event->button() == Qt::RightButton) {
        QGraphicsItem *item = scene->itemAt(event->x(), event->y(), QTransform());
        if(item != 0) {
            scene->removeItem(item);
        }
    }

    if(event->button() == Qt::MidButton) {
        if(scene->itemAt(event->x(), event->y(), QTransform()) == 0) return;

        rotationRequested = true;
        draggedItem = scene->itemAt(event->x(), event->y(), QTransform());
    }
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if(rotationRequested) {
        //draggedItem->setRotation(event->pos().y());
        //draggedItem->setTransformOriginPoint(mapToScene(event->pos()));
        draggedItem->setTransform(QTransform().rotate(event->pos().y()));
        return;
    }

    if(draggedItem) {
        draggedItem->setPos(mapToScene(event->pos().x() - initialX, event->pos().y() - initialY));
    }
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *)
{
    draggedItem = nullptr;
    rotationRequested = false;
}

void MyGraphicsView::resizeEvent(QResizeEvent *)
{
    this->setSceneRect(this->rect());
}

void MyGraphicsView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Plus) {
        if(scene->items().count() == 0) return;

        for(QGraphicsItem *item : scene->items()) {
            item->setScale(1.05 * item->scale());
        }
    }

    if(event->key() == Qt::Key_Minus) {
        if(scene->items().count() == 0) return;

        for(QGraphicsItem *item : scene->items()) {
            item->setScale(0.95 * item->scale());
        }
    }
}

QAbstractGraphicsShapeItem *MyGraphicsView::getNewGraphicsItem(qreal x, qreal y)
{
    QAbstractGraphicsShapeItem *item;
    if(currentItemType == Rectangle) {
        item = new QGraphicsRectItem(x, y, SZ, SZ);
    } else if(currentItemType == Ellipse) {
        item = new QGraphicsEllipseItem(x, y, SZ * 0.7, SZ * 1.2);
    } else if(currentItemType == Star) {
        item = new QGraphicsPolygonItem(QPolygonF({
                                                      { x + 0.5 * SZ,       y + 0.16246 * SZ },
                                                      { x + 0.118034 * SZ,  y + 0.16246 * SZ },
                                                      { x,                  y + 0.525731 * SZ },
                                                      { x - 0.118034 * SZ,  y + 0.16246 * SZ },
                                                      { x - 0.5 * SZ,       y + 0.16246 * SZ },
                                                      { x - 0.190983 * SZ,  y - 0.0620541 * SZ },
                                                      { x - 0.309017 * SZ,  y - 0.425325 * SZ },
                                                      { x,                  y - 0.200811 * SZ },
                                                      { x + 0.309017 * SZ,  y - 0.425325 * SZ },
                                                      { x + 0.190983 * SZ,  y - 0.0620541 * SZ }
                                                  }));
    } else {
        item = new QGraphicsRectItem(x, y, SZ, SZ);
    }

    item->setBrush(QBrush(colors[rand() % colors.size()]));    
    return item;
}

void MyGraphicsView::nextItemType()
{
    currentItemType = ItemType((currentItemType + 1) % ItemTypesCount);
}
