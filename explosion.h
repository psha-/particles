#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "particlecollection.h"
#include "explosionparticle.h"

class Explosion : public ParticleCollection<ExplosionParticle>
{
public:
    void interact();

};

#endif // EXPLOSION_H
