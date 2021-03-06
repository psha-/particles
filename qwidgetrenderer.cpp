#include "qwidgetrenderer.h"

#include <QSurfaceFormat>
#include "glwidget.h"

#include <QGridLayout>
#include <QTimer>


#include <unistd.h>

QWidgetRenderer::QWidgetRenderer(QWidget* window)
    :_window(window), Renderer()
{
    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    _window->show();

    GLWidget *openGL = new GLWidget(&_paintHelper, _window, &_renderables);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(openGL, 0, 1);
    _window->setLayout(layout);

    QTimer *timer = new QTimer(_window);
    _window->connect(timer, &QTimer::timeout, openGL, &GLWidget::animate);
    timer->start(1);
}
