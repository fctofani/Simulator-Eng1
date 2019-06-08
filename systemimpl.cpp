#include "systemimpl.h"

double SystemImpl::getEnergy() const
{
    return energy;
}

void SystemImpl::setEnergy(double value)
{
    energy = value;
}

string SystemImpl::getLabel() const
{
    return label;
}

void SystemImpl::setLabel(const string &value)
{
    label = value;
}

SystemImpl::SystemImpl()
{
    setEnergy(0);
    setLabel("-");
}

SystemImpl::SystemImpl(double energy, string label)
{
    setEnergy(energy);
    setLabel(label);
}

SystemImpl::~SystemImpl()
{

}
