#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model.h"

#include <list>

class ModelImpl : public Model
{
protected:
    string name;
    int start;
    int finish;
    list<System*> systemContainer;
    list<Flow*> flowContainer;
public:
    ModelImpl();
    ModelImpl(ModelImpl&);
    string getName() const;
    void setName(const string &value);
    int getStart() const;
    void setStart(int value);
    int getFinish() const;
    void setFinish(int value);
    list<Flow*> getFlowContainer() const;
    void setFlowContainer(const list<Flow*> &value);
    list<System*> getSystemContainer() const;
    void setSystemContainer(const list<System*> &value);

    list<System*>::iterator getSystemContainerBegin();
    list<System*>::iterator getSystemContainerEnd();

    list<Flow*>::iterator getFlowContainerBegin();
    list<Flow*>::iterator getFlowContainerEnd();

    void add(System*);
    void add(Flow*);

    void run(int, int);

    void showResults();

    virtual ~ModelImpl();

    ModelImpl& operator=(ModelImpl&);

    friend class UnitaryTestsModel;
};

#endif // MODELIMPL_H
