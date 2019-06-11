#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"

#include <list>
using namespace std;

class Model
{
public:
    virtual void setName(const string &value) = 0;
    virtual string getName() const = 0;
    virtual int getStart() const = 0;
    virtual void setStart(int value) = 0;
    virtual int getFinish() const = 0;
    virtual void setFinish(int value) = 0;
    virtual list<Flow*> getFlowContainer() const = 0;
    virtual void setFlowContainer(const list<Flow*> &value) = 0;
    virtual list<System*> getSystemContainer() const = 0;
    virtual void setSystemContainer(const list<System*> &value) = 0;

    virtual list<System*>::iterator getSystemContainerBegin() = 0;
    virtual list<System*>::iterator getSystemContainerEnd() = 0;

    virtual list<Flow*>::iterator getFlowContainerBegin() = 0;
    virtual list<Flow*>::iterator getFlowContainerEnd() = 0;

    virtual void add(System*) = 0;
    virtual void add(Flow*) = 0;

    virtual void run(int, int) = 0;

    virtual void showResults() = 0;
};

#endif // MODEL_H
