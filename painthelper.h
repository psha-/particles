#ifndef PAINTHELPER_H
#define PAINTHELPER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include "renderable.h"

class PaintHelper
{
public:
    PaintHelper();

public:
    void paint(QPainter *painter, QPaintEvent *event, Renderable* renderable);

private:
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
};

#endif
