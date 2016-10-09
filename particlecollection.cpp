#include "particlecollection.h"

ParticleCollection::ParticleCollection(std::vector<Particle*> particles)
    :_position({0,0,0}), _particles(particles)
{
}

void ParticleCollection::interact()
{
    for(auto it = _particles.begin(); it != _particles.end(); it++) {
        (*it)->interact();
    }
}

void ParticleCollection::update()
{
    for(auto it = _particles.begin(); it != _particles.end(); it++) {
        (*it)->update();
    }
}

void ParticleCollection::render(Renderer* renderer)
{
    _renderer = renderer;
    for(auto it = _particles.begin(); it != _particles.end(); it++) {
        (*it)->render(_renderer);
    }
}

ParticleCollection::~ParticleCollection()
{
    for (auto it = _particles.begin() ; it != _particles.end(); ++it)
       {
         delete (*it);
       }
       _particles.clear();
}
