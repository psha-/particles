#include "explosion.h"
#include "rectangle.h"
#include <iostream>
#include <vector>

Explosion::Explosion(Environment* environment, unsigned int interactRadius)
    : ParticleCollection(environment),
      _interactRadius(interactRadius)
{

}

void Explosion::interact()
{
    // TODO: Use a tree to test only the nearby objects
    for(auto& particle1 : _particles) {
        Vec3 p1 = particle1->getPosition();
        std::vector<ExplosionParticle*> boundParticles
                = _particlesByBounds.findItemsBoundBy(Rectangle(p1.x()-_interactRadius, p1.y()-_interactRadius, _interactRadius*2, _interactRadius*2));

        for(auto const & particle2 : boundParticles) {
            if( particle1 == particle2 ) {
                continue;
            }

            Vec3 p2 = particle2->getPosition();

            Vec3 distance = (p1 - p2);

            Vec3 fParticle2Repulsion = 0.1 * distance.normalized() / (distance.lengthSquared()+1);
            particle1->addForce(fParticle2Repulsion);
        }
    }
}
