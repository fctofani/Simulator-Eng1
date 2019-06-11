#include <cmath>
#include <cassert>

#include "system.h"
#include "flowimpl.h"
#include "model.h"
#include "functional.h"

class FlowExp : public FlowImpl
{
public:
    FlowExp(){}
    double execute(){return (getOrigin()->getEnergy()) * 0.01;}
    virtual ~FlowExp(){}
};

class FlowLog : public FlowImpl
{
public:
    FlowLog(){}
    double execute(){return (1 - getDestination()->getEnergy()/70) * 0.01 * getDestination()->getEnergy();}
    virtual ~FlowLog(){}
};

// Functional Tests

void exponentialFunctionalTest()
{
    Model* m = Model::instance();

    System* pop1 = m->createSystem(100, "pop1");
    System* pop2 = m->createSystem(0, "pop2");

    Flow* exponential = m->createFlow<FlowExp>(pop1, pop2, "exponential");

    m->run(0, 100);

    m->showResults();

    assert(fabs(pop1->getEnergy() - 36.6032) <= 0.0001);
    assert(fabs(pop2->getEnergy() - 63.3968) <= 0.0001);

    m->destroySystem(pop1);
    m->destroySystem(pop2);
    m->destroyFlow<FlowExp>(exponential);
}

void logisticalFunctionalTest()
{
    Model* m = Model::instance();

    System* p1 = m->createSystem(100, "p1");
    System* p2 = m->createSystem(10, "p2");

    Flow* logistical = m->createFlow<FlowLog>(p1, p2, "logistical");

    m->run(0, 100);

    m->showResults();

    assert(fabs(p1->getEnergy() - 88.2167) <= 0.0001);
    assert(fabs(p2->getEnergy() - 21.7834) <= 0.0001);

    m->destroySystem(p1);
    m->destroySystem(p2);
    m->destroyFlow<FlowLog>(logistical);
}

void multiExponentialFunctionalTest()
{
    Model* m = Model::instance();

    System* q1 = m->createSystem(100, "q1");
    System* q2 = m->createSystem(0, "q2");
    System* q3 = m->createSystem(100, "q3");
    System* q4 = m->createSystem(0, "q4");
    System* q5 = m->createSystem(0, "q5");
    Flow* f = m->createFlow<FlowExp>(q1, q2, "f");
    Flow* g = m->createFlow<FlowExp>(q1, q3, "g");
    Flow* r = m->createFlow<FlowExp>(q2, q5, "r");
    Flow* t = m->createFlow<FlowExp>(q2, q3, "t");
    Flow* u = m->createFlow<FlowExp>(q3, q4, "u");
    Flow* v = m->createFlow<FlowExp>(q4, q1, "v");

    m->run(0, 100);

    m->showResults();

    assert(fabs(q1->getEnergy() - 31.8513) <= 0.0001);
    assert(fabs(q2->getEnergy() - 18.4003) <= 0.0001);
    assert(fabs(q3->getEnergy() - 77.1143) <= 0.0001);
    assert(fabs(q4->getEnergy() - 56.1728) <= 0.0001);
    assert(fabs(q5->getEnergy() - 16.4612) <= 0.0001);

    m->destroySystem(q1);
    m->destroySystem(q2);
    m->destroySystem(q3);
    m->destroySystem(q4);
    m->destroySystem(q5);
    m->destroyFlow<FlowExp>(f);
    m->destroyFlow<FlowExp>(g);
    m->destroyFlow<FlowExp>(r);
    m->destroyFlow<FlowExp>(t);
    m->destroyFlow<FlowExp>(u);
    m->destroyFlow<FlowExp>(v);
}
