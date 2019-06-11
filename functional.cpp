#include <cmath>
#include <cassert>

#include "systemimpl.h"
#include "flowimpl.h"
#include "modelimpl.h"
#include "functional.h"

class FlowExp : public FlowImpl
{
public:
    FlowExp() : FlowImpl(){}
    FlowExp(System *s1, System *s2, string n) : FlowImpl (s1, s2, n){}
    double execute(){return (getOrigin()->getEnergy()) * 0.01;}
    virtual ~FlowExp(){}
};

class FlowLog : public FlowImpl
{
public:
    FlowLog() : FlowImpl(){}
    FlowLog(System *s1, System *s2, string n) : FlowImpl (s1, s2, n){}
    double execute(){return (1 - getDestination()->getEnergy()/70) * 0.01 * getDestination()->getEnergy();}
    virtual ~FlowLog(){}
};

// Functional Tests

void exponentialFunctionalTest()
{
    Model* m = new ModelImpl();

    System* pop1 = new SystemImpl(100, "pop1");
    System* pop2 = new SystemImpl(0, "pop2");

    Flow* exponential = new FlowExp(pop1, pop2, "exponential");

    m->add(pop1);
    m->add(pop2);
    m->add(exponential);

    m->run(0, 100);

    m->showResults();

    assert(fabs(pop1->getEnergy() - 36.6032) <= 0.0001);
    assert(fabs(pop2->getEnergy() - 63.3968) <= 0.0001);

    delete static_cast<SystemImpl*>(pop1);
    delete static_cast<SystemImpl*>(pop2);
    delete static_cast<FlowImpl*>(exponential);
    delete static_cast<ModelImpl*>(m);
}

void logisticalFunctionalTest()
{
    Model* m = new ModelImpl();

    System* p1 = new SystemImpl(100, "p1");
    System* p2 = new SystemImpl(10, "p2");

    Flow* logistical = new FlowLog(p1, p2, "logistical");

    m->add(p1);
    m->add(p2);
    m->add(logistical);

    m->run(0, 100);

    m->showResults();

    assert(fabs(p1->getEnergy() - 88.2167) <= 0.0001);
    assert(fabs(p2->getEnergy() - 21.7834) <= 0.0001);

    delete static_cast<SystemImpl*>(p1);
    delete static_cast<SystemImpl*>(p2);
    delete static_cast<FlowImpl*>(logistical);
    delete static_cast<ModelImpl*>(m);
}

void multiExponentialFunctionalTest()
{
    Model* m = new ModelImpl();

    System* q1 = new SystemImpl(100, "q1");
    System* q2 = new SystemImpl(0, "q2");
    System* q3 = new SystemImpl(100, "q3");
    System* q4 = new SystemImpl(0, "q4");
    System* q5 = new SystemImpl(0, "q5");
    Flow* f = new FlowExp(q1, q2, "f");
    Flow* g = new FlowExp(q1, q3, "g");
    Flow* r = new FlowExp(q2, q5, "r");
    Flow* t = new FlowExp(q2, q3, "t");
    Flow* u = new FlowExp(q3, q4, "u");
    Flow* v = new FlowExp(q4, q1, "v");

    m->add(q1);
    m->add(q2);
    m->add(q3);
    m->add(q4);
    m->add(q5);

    m->add(f);
    m->add(g);
    m->add(r);
    m->add(t);
    m->add(u);
    m->add(v);

    m->run(0, 100);

    m->showResults();

    assert(fabs(q1->getEnergy() - 31.8513) <= 0.0001);
    assert(fabs(q2->getEnergy() - 18.4003) <= 0.0001);
    assert(fabs(q3->getEnergy() - 77.1143) <= 0.0001);
    assert(fabs(q4->getEnergy() - 56.1728) <= 0.0001);
    assert(fabs(q5->getEnergy() - 16.4612) <= 0.0001);

    delete static_cast<SystemImpl*>(q1);
    delete static_cast<SystemImpl*>(q2);
    delete static_cast<SystemImpl*>(q3);
    delete static_cast<SystemImpl*>(q4);
    delete static_cast<SystemImpl*>(q5);
    delete static_cast<FlowImpl*>(f);
    delete static_cast<FlowImpl*>(g);
    delete static_cast<FlowImpl*>(r);
    delete static_cast<FlowImpl*>(t);
    delete static_cast<FlowImpl*>(u);
    delete static_cast<FlowImpl*>(v);
    delete static_cast<ModelImpl*>(m);
}
