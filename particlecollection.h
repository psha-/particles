#ifndef PARTICLECOLLECTION_H
#define PARTICLECOLLECTION_H

#include "vec3.h"
#include <vector>
#include "particle.h"
#include "renderable.h"

class ParticleCollection : public Renderable
{
public:
    ParticleCollection(std::vector<Particle*> particles = {});

    inline Vec3 getPosition()
    {
        return _position;
    }

    inline void addParticle(Particle* particle)
    {
        particle->render(_renderer);
        _particles.push_back(particle);
    }

    inline std::vector<Particle*>& getParticles()
    {
        return _particles;
    }

    void interact();
    void update();

    void render(Renderer *renderer);

    virtual ~ParticleCollection();

protected:
    std::vector<Particle*> _particles;
    Vec3 _position;
    Renderer* _renderer;
};

#endif // PARTICLECOLLECTION_H
