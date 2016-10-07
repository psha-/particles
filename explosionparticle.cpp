#include "explosionparticle.h"

ExplosionParticle::ExplosionParticle(Vec3 position, Vec3 velocity, ParticleCollection* particles)
    :Particle(position, velocity, {0,0,0}), _particles(particles)
{

}

void ExplosionParticle::update()
{
    // TODO: Use a tree to test only the nearby objects
    for(std::vector<Particle*>::iterator it = _particles->getParticles().begin(); it != _particles->getParticles().end(); it++) {
        if( this == *it ) {
            continue;
        }
        Vec3 distance = (_position - (*it)->getPosition());
        _velocity += distance.normalized()*(3/distance.length()); /*Repulsion*/
    }
    _velocity /= 1.1; /*Drag*/
    _velocity.setY(_velocity.y() + 0.2); /*Gravity*/
    _position += _velocity;

}
