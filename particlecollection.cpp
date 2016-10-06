#include "particlecollection.h"

ParticleCollection::ParticleCollection(std::vector<Particle*> particles)
    :_particles(particles)
{
}

void ParticleCollection::update()
{
    for(auto it = _particles.begin(); it != _particles.end(); it++) {
        (*it)->update();
    }
}

void ParticleCollection::render(Renderer* renderer)
{
    for(auto it = _particles.begin(); it != _particles.end(); it++) {
        renderer->addRenderable(*it);
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
