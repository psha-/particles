#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec3.h"
#include "renderable.h"
#include "renderer.h"

class Particle : public Renderable
{
public:
    Particle(Vec3 position = {0,0,0}, Vec3 velocity= {0,0,0}, Vec3 acceleration = {0,0,0});

    inline void setPosition(Vec3 position)
    {
        _position = position;
    }

    inline void setVelocity(Vec3 velocity)
    {
        _velocity = velocity;
    }

    inline void setAcceleration(Vec3 acceleration)
    {
        _acceleration = acceleration;
    }

    inline Vec3 getPosition()
    {
        return _position;
    }

    virtual void interact();
    void update();
    void render(Renderer* renderer);

protected:
    Vec3 _position;
    Vec3 _velocity;
    Vec3 _acceleration;
};

#endif // PARTICLE_H
