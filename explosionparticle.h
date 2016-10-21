#ifndef EXPLOSIONPARTICLE_H
#define EXPLOSIONPARTICLE_H

#include "particle.h"
#include "vec3.h"

class ExplosionParticle : public Particle
{
public:
    ExplosionParticle(float mass, Renderer* renderer, Vec3 position, Vec3 velocity, Vec3 acceleration);

    inline float getSize()
    {
        return _mass;
    }
    inline float mass()
    {
        return _mass;
    }
    inline void addForce(Vec3 force)
    {
        _acceleration += force / _mass;
    }

private:
    float _mass;
};

#endif // EXPLOSIONPARTICLE_H
