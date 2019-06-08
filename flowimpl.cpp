#include "flowimpl.h"

SystemImpl* FlowImpl::getOrigin() const
{
    return origin;
}

void FlowImpl::setOrigin(SystemImpl *value)
{
    origin = value;
}

SystemImpl* FlowImpl::getDestination() const
{
    return destination;
}

void FlowImpl::setDestination(SystemImpl *value)
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

void FlowImpl::connect(SystemImpl *system1, SystemImpl *system2)
{
    setOrigin(system1);
    setDestination(system2);
}

FlowImpl::~FlowImpl()
{

}

FlowImpl::FlowImpl()
{
    setCurrentEnergy(0);
    connect(nullptr, nullptr);
    setName("-");
}

FlowImpl::FlowImpl(SystemImpl *s1, SystemImpl *s2, string name)
{
    setCurrentEnergy(0);
    connect(s1, s2);
    setName(name);
}
