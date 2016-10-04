#ifndef PARTICLECOLLECTION_H
#define PARTICLECOLLECTION_H

#include "vec3.h"
#include <vector>
#include "particle.h"
#include "renderable.h"

class ParticleCollection : public Renderable
{
public:
    ParticleCollection(std::vector<Particle*> particles);

    inline Vec3 getPosition()
    {
        return _position;
    }
    void update();
    void render(Renderer *renderer);

protected:
    std::vector<Particle*> _particles;
    Vec3 _position;
};

#endif // PARTICLECOLLECTION_H
