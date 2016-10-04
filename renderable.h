#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "vec3.h"

class Renderer;

class Renderable
{
public:
    Renderable();

    virtual Vec3 getPosition() = 0;
    virtual void update() = 0;
    virtual void render(Renderer* renderer) = 0;
};

#endif // RENDERABLE_H
