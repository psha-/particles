#include "interestingenvironment.h"
#include "particle.h"

InterestingEnvironment::InterestingEnvironment()
{

}

void InterestingEnvironment::applyField(Particle* particle)
{
    particle->addForce(-0.01*(particle->getVelocity().lengthSquared()*particle->getVelocity().normalized()));
}
