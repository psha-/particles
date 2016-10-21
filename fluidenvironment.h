#ifndef FLUIDENVIRONMENT_H
#define FLUIDENVIRONMENT_H

#include "environment.h"

class Particle;

class FluidEnvironment : public Environment
{
public:
    FluidEnvironment();
    void applyField(Particle *particle);
};

#endif // FLUIDENVIRONMENT_H
