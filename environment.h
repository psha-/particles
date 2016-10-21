#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "vec3.h"

class Particle;

class Environment
{
public:
    Environment();
    virtual void applyField(Particle* particle) = 0;
};

#endif // ENVIRONMENT_H
