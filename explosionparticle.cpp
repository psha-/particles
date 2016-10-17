#include "explosionparticle.h"

ExplosionParticle::ExplosionParticle(float mass, Renderer* renderer, Vec3 position, Vec3 velocity, Vec3 acceleration)
    :_mass(mass), Particle(renderer, position, velocity, acceleration)
{
}
