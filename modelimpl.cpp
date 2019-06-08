#include <iostream>
#include "modelimpl.h"

string ModelImpl::getName() const
{
    return name;
}

void ModelImpl::setName(const string &value)
{
    name = value;
}

int ModelImpl::getStart() const
{
    return start;
}

void ModelImpl::setStart(int value)
{
    if(value < 0) value = 0;
    start = value;
}

int ModelImpl::getFinish() const
{
    return finish;
}

void ModelImpl::setFinish(int value)
{
    if(value < start) value = start;
    finish = value;
}

list<FlowImpl *> ModelImpl::getFlowContainer() const
{
    return flowContainer;
}

void ModelImpl::setFlowContainer(const list<FlowImpl *> &value)
{
    flowContainer = value;
}

list<SystemImpl *> ModelImpl::getSystemContainer() const
{
    return systemContainer;
}

void ModelImpl::setSystemContainer(const list<SystemImpl *> &value)
{
    systemContainer = value;
}

list<SystemImpl*>::iterator ModelImpl::getSystemContainerBegin()
{
    return systemContainer.begin();
}

list<SystemImpl*>::iterator ModelImpl::getSystemContainerEnd()
{
    return systemContainer.end();
}

list<FlowImpl*>::iterator ModelImpl::getFlowContainerBegin()
{
    return flowContainer.begin();
}

list<FlowImpl*>::iterator ModelImpl::getFlowContainerEnd()
{
    return flowContainer.end();
}

void ModelImpl::add(SystemImpl *system)
{
    systemContainer.push_back(system);
}

void ModelImpl::add(FlowImpl *flow)
{
    flowContainer.push_back(flow);
}

void ModelImpl::run(int start, int finish)
{
    setStart(start);
    setFinish(finish);

    for (int i = start; i < finish; ++i) {
        for (auto flow : flowContainer) {
            flow->setCurrentEnergy(flow->execute());
        }

        for (list<FlowImpl*>::iterator it = getFlowContainerBegin(); it != getFlowContainerEnd(); ++it) {
            SystemImpl* source = (*it)->getOrigin();
            if(source != nullptr) source->setEnergy(source->getEnergy() - (*it)->getCurrentEnergy());

            SystemImpl* sink = (*it)->getDestination();
            if(sink != nullptr) sink->setEnergy(sink->getEnergy() + (*it)->getCurrentEnergy());
        }
    }
}

void ModelImpl::showResults()
{
    cout << "_______________________________________________________________________________________";
    cout << "\n Results: \n" << endl;
    for (auto system : systemContainer) {
        cout << " System " << system->getLabel() << "'s energy: " << system->getEnergy() << endl;
    }
    cout << "_______________________________________________________________________________________" << endl;
}

ModelImpl::~ModelImpl()
{

}

ModelImpl::ModelImpl()
{

}
