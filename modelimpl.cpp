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

list<Flow*> ModelImpl::getFlowContainer() const
{
    return flowContainer;
}

void ModelImpl::setFlowContainer(const list<Flow*> &value)
{
    flowContainer = value;
}

list<System*> ModelImpl::getSystemContainer() const
{
    return systemContainer;
}

void ModelImpl::setSystemContainer(const list<System*> &value)
{
    systemContainer = value;
}

list<System*>::iterator ModelImpl::getSystemContainerBegin()
{
    return systemContainer.begin();
}

list<System*>::iterator ModelImpl::getSystemContainerEnd()
{
    return systemContainer.end();
}

list<Flow*>::iterator ModelImpl::getFlowContainerBegin()
{
    return flowContainer.begin();
}

list<Flow*>::iterator ModelImpl::getFlowContainerEnd()
{
    return flowContainer.end();
}

void ModelImpl::add(System*system)
{
    systemContainer.push_back(system);
}

void ModelImpl::add(Flow*flow)
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

        for (list<Flow*>::iterator it = getFlowContainerBegin(); it != getFlowContainerEnd(); ++it) {
            System* source = (*it)->getOrigin();
            if(source != nullptr) source->setEnergy(source->getEnergy() - (*it)->getCurrentEnergy());

            System* sink = (*it)->getDestination();
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

ModelImpl &ModelImpl::operator=(ModelImpl &copy)
{
    if(&copy == this) return (*this);

    name = copy.name;
    start = copy.start;
    finish = copy.finish;

    for (auto&& item : flowContainer) {
        delete item;
    }
    for (auto&& item : systemContainer){
        delete item;
    }

    System* aux;
    for(list<System*>::iterator it = copy.getSystemContainerBegin(); it != copy.getSystemContainerEnd(); ++it){
        aux = (*it);
        add(aux);
    }
    Flow* bux;
    for(list<Flow*>::iterator it = copy.getFlowContainerBegin(); it != copy.getFlowContainerEnd(); ++it){
        bux = (*it);
        add(bux);
    }

    return (*this);
}

ModelImpl::ModelImpl()
{
    setStart(0);
    setFinish(100);
    setName("-");
}

ModelImpl::ModelImpl(ModelImpl &copy)
{
    name = copy.name;
    start = copy.start;
    finish = copy.finish;

    for (auto&& item : flowContainer) {
        delete item;
    }
    for (auto&& item : systemContainer){
        delete item;
    }

    System* aux;
    for(list<System*>::iterator it = copy.getSystemContainerBegin(); it != copy.getSystemContainerEnd(); ++it){
        aux = (*it);
        add(aux);
    }
    Flow* bux;
    for(list<Flow*>::iterator it = copy.getFlowContainerBegin(); it != copy.getFlowContainerEnd(); ++it){
        bux = (*it);
        add(bux);
    }

}
