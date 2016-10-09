#ifndef EXPLOSIONPARTICLE_H
#define EXPLOSIONPARTICLE_H

#include "particle.h"
#include "particlecollection.h"
#include "vec3.h"

class ExplosionParticle : public Particle
{
public:
    ExplosionParticle(Vec3 position, Vec3 velocity, ParticleCollection* particles);

    void interact();

private:
    ParticleCollection* _particles;
};

#endif // EXPLOSIONPARTICLE_H
