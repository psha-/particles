#include "glwidget.h"
#include "painthelper.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QTimer>

GLWidget::GLWidget(PaintHelper *paintHelper, QWidget *parent, std::vector<Renderable*>* renderables)
    : QOpenGLWidget(parent), _paintHelper(paintHelper), _renderables(renderables)
{
    setFixedSize(600, 600);
    setAutoFillBackground(false);
}

void GLWidget::animate()
{
    update();
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    PaintHelper::paint(PaintHelper::getPainter(), this, event, _renderables);
}
