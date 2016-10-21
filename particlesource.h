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
    ParticleSource(Renderer* renderer, ParticleCollection<T>* particles, Vec3 begin, Vec3 end, Vec3 direction = {0,0,0}, float gravity = 0)
        :_renderer(renderer),
        _particles(particles),
        _generator(_rd()),
        _distX(begin.x(), end.x()),
        _distY(begin.y(), end.y()),
        _distZ(begin.z(), end.z()),
        _distMass(2.0, 2.0),
        _direction(direction),
        _gravity(gravity)
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
    Vec3 _direction;
    float _gravity;
};

template<>
ExplosionParticle* ParticleSource<ExplosionParticle>::next()
{
    return new ExplosionParticle(_distMass(_generator), _renderer, {_distX(_generator), _distY(_generator), _distZ(_generator)}, _direction, {0, _gravity, 0});
}

#endif // PARTICLESOURCE_H
