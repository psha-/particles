#include "explosionparticle.h"

ExplosionParticle::ExplosionParticle(Vec3 position, Vec3 velocity, ParticleCollection* particles)
    :Particle(position, velocity, {0,0,0}), _particles(particles)
{

}


void ExplosionParticle::interact()
{
    // TODO: Use a tree to test only the nearby objects
    for(std::vector<Particle*>::iterator it = _particles->getParticles().begin(); it != _particles->getParticles().end(); it++) {
        if( this == *it ) {
            continue;
        }
        Vec3 distance = (_position - (*it)->getPosition());
        _velocity += distance.normalized()*(1/(distance.length()+1)); /*Repulsion*/
    }
    _velocity /= 2; /*Drag*/
//    _velocity.setY(_velocity.y() + 0.3); /*Gravity*/
}
