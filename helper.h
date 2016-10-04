#ifndef HELPER_H
#define HELPER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include "renderable.h"

class Helper
{
public:
    Helper();

public:
    void paint(QPainter *painter, QPaintEvent *event, Renderable* renderable);

private:
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
};

#endif
