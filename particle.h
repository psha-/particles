#ifndef PARTICLE_H
#define PARTICLE_H

#include "vec3.h"
#include "renderable.h"
#include "boundable.h"

class Renderer;

class Particle : public Renderable, public Boundable
{
public:
    Particle(Renderer* renderer, Vec3 position, Vec3 velocity = {0,0,0}, Vec3 acceleration = {0,0,0});

    inline void setPosition(Vec3 position)
    {
        _position = position;
    }

    inline void setVelocity(Vec3 velocity)
    {
        _velocity = velocity;
    }
    inline Vec3 getVelocity() const
    {
        return _velocity;
    }

    inline void setAcceleration(Vec3 acceleration)
    {
        _acceleration = acceleration;
    }

    Vec3 getAcceleration() const
    {
        return _acceleration;
    }

    inline Vec3 getPosition()
    {
        return _position;
    }

    inline void update()
    {
        if(--_lifespan <= 0 && !_isDead) {
            _die();
        }
        _velocity += _acceleration;
        _position += 5*_velocity;
    }

    virtual void addForce(Vec3 force) = 0;


protected:
    float _lifespan;
    bool _isDead;
    Vec3 _position;
    Vec3 _velocity;
    Vec3 _acceleration;
    void _die()
    {
        _isDead = true;
    }
};

#endif // PARTICLE_H
