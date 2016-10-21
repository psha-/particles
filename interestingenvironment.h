#ifndef INTERESTINGENVIRONMENT_H
#define INTERESTINGENVIRONMENT_H

#include "environment.h"

class Particle;

class InterestingEnvironment : public Environment
{
public:
    InterestingEnvironment();
    virtual void applyField(Particle* particle);

};

#endif // INTERESTINGENVIRONMENT_H
