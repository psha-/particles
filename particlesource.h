#ifndef PARTICLESOURCE_H
#define PARTICLESOURCE_H

#include <random>
#include "particle.h"
#include "particlecollection.h"
#include "explosionparticle.h"
#include "vec3.h"

template <typename T>
class ParticleSource
{
public:
    ParticleSource(ParticleCollection* particles, Vec3 begin, Vec3 end)
        :_particles(particles),
        _generator(_rd()),
        _distX(begin.x(), end.x()),
        _distY(begin.y(), end.y()),
        _distZ(begin.z(), end.z())
    {
    }

    T* next();

private:
    ParticleCollection* _particles;
    std::random_device _rd;
    std::mt19937 _generator;
    std::uniform_int_distribution<> _distX;
    std::uniform_int_distribution<> _distY;
    std::uniform_int_distribution<> _distZ;
};

template <typename T>
T* ParticleSource<T>::next()
{
    return new T({_distX(_generator), _distY(_generator), _distZ(_generator)});
}

template<>
ExplosionParticle* ParticleSource<ExplosionParticle>::next()
{
    return new ExplosionParticle({_distX(_generator), _distY(_generator), _distZ(_generator)}, {0, 0, 0},_particles);
}

#endif // PARTICLESOURCE_H
