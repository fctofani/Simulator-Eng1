#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "systemimpl.h"
#include "flowimpl.h"

#include <list>

class ModelImpl
{
protected:
    string name;
    int start;
    int finish;
    list<SystemImpl*> systemContainer;
    list<FlowImpl*> flowContainer;
public:
    ModelImpl();
    string getName() const;
    void setName(const string &value);
    int getStart() const;
    void setStart(int value);
    int getFinish() const;
    void setFinish(int value);
    list<FlowImpl *> getFlowContainer() const;
    void setFlowContainer(const list<FlowImpl *> &value);
    list<SystemImpl *> getSystemContainer() const;
    void setSystemContainer(const list<SystemImpl *> &value);

    list<SystemImpl*>::iterator getSystemContainerBegin();
    list<SystemImpl*>::iterator getSystemContainerEnd();

    list<FlowImpl*>::iterator getFlowContainerBegin();
    list<FlowImpl*>::iterator getFlowContainerEnd();

    void add(SystemImpl*);
    void add(FlowImpl*);

    void run(int, int);

    void showResults();

    virtual ~ModelImpl();
};

#endif // MODELIMPL_H
