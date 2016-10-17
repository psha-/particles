#include "renderable.h"

Renderable::Renderable(Renderer* renderer)
    : _renderer(renderer)
{
    _renderer->addRenderable(this);
}
