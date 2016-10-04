#include "temporalparticle.h"

TemporalParticle::TemporalParticle(Particle particle, float lifespan)
    :Particle(particle), _isDead(false), _lifespan(lifespan)
{
}

void TemporalParticle::update()
{
    if(--_lifespan <= 0 && !_isDead) {
        die();
    }
    else {
        _velocity += _acceleration;
        _position += _velocity;
    }
}

