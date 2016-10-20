#include "explosion.h"
#include "rectangle.h"
#include <iostream>
#include <vector>

Explosion::Explosion(unsigned int interactRadius)
    : _interactRadius(interactRadius)
{

}

void Explosion::interact()
{
    // TODO: Use a tree to test only the nearby objects
    for(auto& particle1 : _particles) {
        Vec3 p1 = particle1->getPosition();
        float m1 = particle1->mass();

        std::vector<ExplosionParticle*> boundParticles
                = _particlesByBounds.findItemsBoundBy(Rectangle(p1.x()-_interactRadius, p1.y()-_interactRadius, _interactRadius*2, _interactRadius*2));

        Vec3 v1 = particle1->getVelocity();
        for(auto const & particle2 : boundParticles) {
            if( particle1 == particle2 ) {
                continue;
            }

            Vec3 p2 = particle2->getPosition();

            Vec3 z(0,0,1);
            //int dir = Vec3::dotProduct(z, Vec3::crossProduct(p1, p2)) > 0 ? -1: 1;
            Vec3 distance = (p1 - p2);//*dir;

            Vec3 particle2RepulsionV = 1 * distance.normalized() / (distance.length()+1) / m1;
            v1 += particle2RepulsionV;
        }
        float drag = 0.6*m1;
        v1 /= drag;
        particle1->setVelocity( v1 );
    }
}
