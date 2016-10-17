#ifndef QWIDGETRENDERER_H
#define QWIDGETRENDERER_H

#include "painthelper.h"
#include <vector>

class Renderable;
class Renderer;

class QWidgetRenderer : public Renderer
{
public:
    QWidgetRenderer(QWidget* window);

private:
    PaintHelper _paintHelper;
    QWidget* _window;
};

#endif // QWIDGETRENDERER_H
