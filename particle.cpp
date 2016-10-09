#include "particle.h"

Particle::Particle(Vec3 position, Vec3 velocity, Vec3 acceleration)
    :_position(position), _velocity(velocity), _acceleration(acceleration)
{
}

void Particle::interact()
{
}

void Particle::update()
{
    _velocity += _acceleration;
    _position += _velocity;
}

void Particle::render(Renderer* renderer)
{
    renderer->addRenderable(this);
}
