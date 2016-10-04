#ifndef TEMPORALPARTICLE_H
#define TEMPORALPARTICLE_H

#include "particle.h"

class TemporalParticle : public Particle
{
public:
    TemporalParticle(Particle particle, float lifespan);

    void update();

    inline bool getIsDead()
    {
        return _isDead;
    }

protected:
    float _lifespan;
    bool _isDead;
    void die()
    {
        _isDead = true;
    }
};

#endif // TEMPORALPARTICLE_H
