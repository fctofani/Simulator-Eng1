#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "systemimpl.h"

class FlowImpl
{
protected:
    SystemImpl* origin;
    SystemImpl* destination;
    double currentEnergy;
    string name;
public:
    FlowImpl();
    FlowImpl(SystemImpl*, SystemImpl*, string);
    SystemImpl *getOrigin() const;
    void setOrigin(SystemImpl *value);
    SystemImpl *getDestination() const;
    void setDestination(SystemImpl *value);
    double getCurrentEnergy() const;
    void setCurrentEnergy(double value);
    string getName() const;
    void setName(const string &value);

    void connect(SystemImpl*, SystemImpl*);

    virtual double execute() = 0;

    virtual ~FlowImpl();
};

#endif // FLOWIMPL_H
