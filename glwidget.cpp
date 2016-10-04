#include "glwidget.h"
#include "helper.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QTimer>

GLWidget::GLWidget(Helper *helper, QWidget *parent, std::vector<Renderable*>* renderables)
    : QOpenGLWidget(parent), helper(helper), _renderables(renderables)
{
    setFixedSize(400, 400);
    setAutoFillBackground(false);
}

void GLWidget::animate()
{
    update();
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), QBrush(QColor(64, 32, 64)));
    for( auto it = _renderables->begin(); it != _renderables->end(); it++) {
        helper->paint(&painter, event, *it);
        (*it)->update();
    }
    painter.end();
}
