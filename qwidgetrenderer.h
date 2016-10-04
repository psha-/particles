#ifndef QWIDGETRENDERER_H
#define QWIDGETRENDERER_H

#include "renderable.h"
#include "renderer.h"
#include "helper.h"
#include <vector>

class QWidgetRenderer : public Renderer
{
public:
    QWidgetRenderer(QWidget* window);
    void start();

private:
    Helper helper;
    QWidget* _window;
};

#endif // QWIDGETRENDERER_H
