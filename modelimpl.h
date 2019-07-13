#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model.h"

#include <list>

/*! \class Model (Implementation)
 * \brief Model represents a conjunction of systems and flows.
 *
 * \details The model stores all systems and flows you want to evaluate. The model would be a country which stores systems (cities) and flows
 * (people changing cities), for example.
*/

class ModelImpl : public Model
{
protected:
    string name;
    int start;
    int finish;
    list<System*> systemContainer;
    list<Flow*> flowContainer;

    ModelImpl();
    ModelImpl(ModelImpl&);
    ModelImpl& operator=(ModelImpl&);

    void add(System*);
    void add(Flow*);
    void remove(System*);
    void remove(Flow*);

public:
    static ModelImpl* instance();

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

    System* createSystem(double, string);
//    Flow* createFlow(System*, System*, string);

    void destroySystem(System*);
//    void destroyFlow(Flow*);

    void run(int, int);

    void showResults();

    virtual ~ModelImpl();    

    friend class UnitaryTestsModel;
};

#endif // MODELIMPL_H
