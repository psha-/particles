#ifndef RENDERER_H
#define RENDERER_H

#include "renderable.h"
#include <vector>

class Renderer
{
public:
    Renderer();

    virtual void start() = 0;
    virtual void addRenderable(Renderable* renderable);

protected:
    std::vector<Renderable*> _renderables;
};

#endif // RENDERER_H
