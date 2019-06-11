#ifndef FLOW_H
#define FLOW_H

#include "system.h"

class Flow
{
public:
    virtual System *getOrigin() const = 0;
    virtual void setOrigin(System *value) = 0;
    virtual System *getDestination() const = 0;
    virtual void setDestination(System *value) = 0;
    virtual double getCurrentEnergy() const = 0;
    virtual void setCurrentEnergy(double value) = 0;
    virtual string getName() const = 0;
    virtual void setName(const string &value) = 0;

    virtual void connect(System*, System*) = 0;
    virtual double execute() = 0;
};

#endif // FLOW_H
