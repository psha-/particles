#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "particlecollection.h"
#include "explosionparticle.h"

class Explosion : public ParticleCollection<ExplosionParticle>
{
public:
    Explosion(unsigned int _interactRadius = _defaultInteractRadius);
    void interact();
private:
    unsigned int _interactRadius;
    static unsigned int const _defaultInteractRadius = 50;
};

#endif // EXPLOSION_H
