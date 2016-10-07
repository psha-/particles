#ifndef QWIDGETRENDERER_H
#define QWIDGETRENDERER_H

#include "renderable.h"
#include "renderer.h"
#include "painthelper.h"
#include <vector>

class QWidgetRenderer : public Renderer
{
public:
    QWidgetRenderer(QWidget* window);

private:
    PaintHelper helper;
    QWidget* _window;
};

#endif // QWIDGETRENDERER_H
