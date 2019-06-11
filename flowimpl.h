#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "flow.h"

class FlowImpl : public Flow
{
protected:
    System* origin;
    System* destination;
    double currentEnergy;
    string name;
public:
    FlowImpl();
    FlowImpl(System*, System*, string);
    FlowImpl(Flow*);
    System *getOrigin() const;
    void setOrigin(System *value);
    System *getDestination() const;
    void setDestination(System *value);
    double getCurrentEnergy() const;
    void setCurrentEnergy(double value);
    string getName() const;
    void setName(const string &value);

    void connect(System*, System*);
    virtual double execute() = 0;

    virtual ~FlowImpl();

    FlowImpl& operator=(FlowImpl&);

    friend class UnitaryTestsFlow;
};

#endif // FLOWIMPL_H
