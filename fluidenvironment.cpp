#include "fluidenvironment.h"
#include "particle.h"

FluidEnvironment::FluidEnvironment()
{

}

void FluidEnvironment::applyField(Particle *particle)
{
    particle->addForce(-1*(particle->getVelocity().lengthSquared()*particle->getAcceleration().normalized()));
}
