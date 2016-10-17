#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "vec3.h"
#include "renderer.h"

class Renderable
{
public:
    Renderable(Renderer* renderer);
    virtual Vec3 getPosition() = 0;
    virtual void update() = 0;
    inline virtual float getSize()
    {
        return 0;
    }

protected:
    Renderer* _renderer;
};

#endif // RENDERABLE_H
