#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec3.h"
#include "renderable.h"
#include "renderer.h"

class Particle : public Renderable
{
public:
    Particle(Vec3 position, Vec3 velocity, Vec3 acceleration);

    inline void setLocation(Vec3 position)
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

    void update();
    void render(Renderer* renderer);

protected:
    Vec3 _position;
    Vec3 _velocity;
    Vec3 _acceleration;
};

#endif // PARTICLE_H
