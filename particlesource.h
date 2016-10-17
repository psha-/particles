#ifndef PARTICLESOURCE_H
#define PARTICLESOURCE_H

#include <random>
#include "explosionparticle.h"
#include "vec3.h"

template<typename T>
class ParticleCollection;
class Particle;
class Renderer;

template <typename T>
class ParticleSource
{
public:
    ParticleSource(Renderer* renderer, ParticleCollection<T>* particles, Vec3 begin, Vec3 end)
        :_renderer(renderer),
        _particles(particles),
        _generator(_rd()),
        _distX(begin.x(), end.x()),
        _distY(begin.y(), end.y()),
        _distZ(begin.z(), end.z()),
        _distMass(1.0, 4.0)
    {
    }

    T* next();

private:
    Renderer* _renderer;
    ParticleCollection<T>* _particles;
    std::random_device _rd;
    std::mt19937 _generator;
    std::uniform_int_distribution<> _distX;
    std::uniform_int_distribution<> _distY;
    std::uniform_int_distribution<> _distZ;
    std::uniform_int_distribution<> _distMass;
};

//template <typename T>
//T* ParticleSource<T>::next()
//{
//    return new T({_distX(_generator), _distY(_generator), _distZ(_generator)});
//}

template<>
ExplosionParticle* ParticleSource<ExplosionParticle>::next()
{
    return new ExplosionParticle(_distMass(_generator), _renderer, {_distX(_generator), _distY(_generator), _distZ(_generator)}, {0, 0, 0}, {0, 0/*Gravity*/, 0});
}

#endif // PARTICLESOURCE_H
