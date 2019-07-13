#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"

#include <list>
using namespace std;

class Model
{
protected:
    virtual void add(System*) = 0;
    virtual void add(Flow*) = 0;
    virtual void remove(System*) = 0;
    virtual void remove(Flow*) = 0;
public:
    static Model* instance();

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

    virtual System* createSystem(double, string) = 0;

    template<class T>
    Flow* createFlow(System*s1, System*s2, string name){
        Flow* f = new T();
        f->connect(s1, s2);
        f->setName(name);
        add(f);
        return f;
    }

    template<class T>
    void destroyFlow(Flow* f){
        remove(f);
        delete static_cast<T*>(f);
    }

    virtual void destroySystem(System*) = 0;

    virtual void run(int, int) = 0;

    virtual void showResults() = 0;
};

#endif // MODEL_H
