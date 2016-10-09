#ifndef PAINTHELPER_H
#define PAINTHELPER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include "renderable.h"
#include <memory>
#include <vector>

class PaintHelper
{
public:
    PaintHelper();

public:
    static std::unique_ptr<QPainter> getPainter();
    static void paint(std::unique_ptr<QPainter> painter, QWidget* widget, QPaintEvent *event, std::vector<Renderable*>* renderables);

};

#endif
