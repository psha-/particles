#ifndef PARTICLECOLLECTION_H
#define PARTICLECOLLECTION_H

#include "vec3.h"
#include <vector>
#include "quadtree.h"
#include "environment.h"
#include <memory>

class Renderable;
class Environment;

template<typename T>
class ParticleCollection
{
public:
    ParticleCollection(/*std::vector<T*> particles = {}*/Environment* environment)
        : _environment(environment),
          _particlesByBounds(600, 600)
//          _particles(particles)
    {
//        for(auto& particle : _particles) {
//            _particlesByBounds.add(particle);
//        }
    }

    inline void addParticle(T* particle)
    {
        _particles.push_back(particle);
        _particlesByBounds.add(particle);
    }

    inline std::vector<T*>& getParticles()
    {
        return _particles;
    }

    virtual void interact() = 0;
    virtual void update()
    {
        for(auto& particle : _particles) {
            Rectangle prevBounds = particle->bounds();
            particle->update();
            _particlesByBounds.update(particle, prevBounds);
            _environment->applyField(particle);
        }
    }

    virtual ~ParticleCollection()
    {
        for (auto it = _particles.begin() ; it != _particles.end(); ++it)
           {
             delete (*it);
           }
           _particles.clear();
    }

protected:
    Environment* _environment;
    QuadTree<T*> _particlesByBounds;
    std::vector<T*> _particles;
    Vec3 _position;
};

#endif // PARTICLECOLLECTION_H
