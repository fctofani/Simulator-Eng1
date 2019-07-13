#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "flow.h"

/*! \class Flow (Implementation)
 *  \brief Flow, which represents a exchange of energy between any quantity of systems.
 *
 *  \details Flow may be represented via the number of people who migrate from city a to city b, where cities would be systems.
*/
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
