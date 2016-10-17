#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

class Renderable;

class Renderer
{
public:
    Renderer();

    void addRenderable(Renderable* renderable);

protected:
    std::vector<Renderable*> _renderables;
};

#endif // RENDERER_H
