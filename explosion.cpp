#include "explosion.h"
#include "rectangle.h"
#include <iostream>
#include <vector>

void Explosion::interact()
{
    // TODO: Use a tree to test only the nearby objects
    for(auto& particle1 : _particles) {

        std::vector<ExplosionParticle*> boundParticles
                = _particlesByBounds.findItemsBoundBy(Rectangle(particle1->getPosition().x()-25, particle1->getPosition().y()-25, 50, 50));

        for(auto const & particle2 : boundParticles) {
            if( particle1 == particle2 ) {
                continue;
            }
            Vec3 distance = (particle1->getPosition() - particle2->getPosition());

            particle1->setAcceleration( particle1->getAcceleration() + distance.normalized()*(0.5/(distance.length()+1))/particle1->mass() ); /*Repulsion*/
        }
        particle1->setVelocity( particle1->getVelocity() / (5*particle1->mass()) ); /*Drag*/
    }
}
