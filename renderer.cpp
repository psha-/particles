#include "renderer.h"

Renderer::Renderer()
    :_renderables()
{
}

void Renderer::addRenderable(Renderable* renderable)
{
    _renderables.push_back(renderable);
}
