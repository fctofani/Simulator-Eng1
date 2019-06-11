#include "flowimpl.h"

System* FlowImpl::getOrigin() const
{
    return origin;
}

void FlowImpl::setOrigin(System *value)
{
    origin = value;
}

System* FlowImpl::getDestination() const
{
    return destination;
}

void FlowImpl::setDestination(System *value)
{
    destination = value;
}

double FlowImpl::getCurrentEnergy() const
{
    return currentEnergy;
}

void FlowImpl::setCurrentEnergy(double value)
{
    currentEnergy = value;
}

string FlowImpl::getName() const
{
    return name;
}

void FlowImpl::setName(const string &value)
{
    name = value;
}

void FlowImpl::connect(System *system1, System *system2)
{
    setOrigin(system1);
    setDestination(system2);
}

FlowImpl::~FlowImpl()
{

}

FlowImpl &FlowImpl::operator=(FlowImpl &copy)
{
    if(&copy == this) return (*this);

    origin = copy.origin;
    destination = copy.destination;
    currentEnergy = copy.currentEnergy;
    name = copy.name;

    return (*this);
}

FlowImpl::FlowImpl()
{
    setCurrentEnergy(0);
    connect(nullptr, nullptr);
    setName("-");
}

FlowImpl::FlowImpl(System *s1, System *s2, string name)
{
    setCurrentEnergy(0);
    connect(s1, s2);
    setName(name);
}

FlowImpl::FlowImpl(Flow *copy)
{
    origin = copy->getOrigin();
    destination = copy->getDestination();
    currentEnergy = copy->getCurrentEnergy();
    name = copy->getName();
}
