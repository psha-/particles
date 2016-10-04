#include "renderer.h"

Renderer::Renderer()
{
}

void Renderer::addRenderable(Renderable* renderable)
{
    _renderables.push_back(renderable);
}
