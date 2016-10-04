#include "helper.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

Helper::Helper()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}

void Helper::paint(QPainter *painter, QPaintEvent *event, Renderable* renderable)
{
    painter->translate(renderable->getPosition().x(), renderable->getPosition().y());

    painter->save();
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);

    painter->drawEllipse(QRectF(0, 0, 10, 10));
    painter->restore();
}
