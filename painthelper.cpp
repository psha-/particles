#include "painthelper.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

PaintHelper::PaintHelper()
{
}

std::unique_ptr<QPainter> PaintHelper::getPainter()
{
    return std::unique_ptr<QPainter>(new QPainter());
}

void PaintHelper::paint(std::unique_ptr<QPainter> painter, QWidget* widget, QPaintEvent *event, std::vector<Renderable*>* renderables)
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    QBrush circleBrush = QBrush(gradient);
    QPen circlePen = QPen(Qt::black);
    circlePen.setWidth(1);

    painter->begin(widget);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillRect(event->rect(), QBrush(QColor(64, 32, 64)));
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);


    for( int i=0; i<renderables->size(); i++) {
        painter->save();
        painter->translate((*renderables)[i]->getPosition().x(), (*renderables)[i]->getPosition().y());

        painter->drawEllipse(QRectF(0, 0, 3, 3));
        painter->restore();
    }
    painter->end();


}
