#include "particle.h"

Particle::Particle(Renderer* renderer, Vec3 position, Vec3 velocity, Vec3 acceleration)
    : _isDead(false),
      _lifespan(100),
      _position(position),
      _velocity(velocity),
      _acceleration(acceleration),
      Renderable(renderer),
      Boundable(position.x(), position.y(), 1, 1)
{
}

