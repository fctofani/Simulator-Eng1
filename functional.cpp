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
    FlowExp(SystemImpl *s1, SystemImpl *s2, string n) : FlowImpl (s1, s2, n){}
    double execute(){return (getOrigin()->getEnergy()) * 0.01;}
    ~FlowExp(){}
};

class FlowLog : public FlowImpl
{
public:
    FlowLog() : FlowImpl(){}
    FlowLog(SystemImpl *s1, SystemImpl *s2, string n) : FlowImpl (s1, s2, n){}
    double execute(){return (1 - getDestination()->getEnergy()/70) * 0.01 * getDestination()->getEnergy();}
    ~FlowLog(){}
};

// Functional Tests

void exponentialFunctionalTest()
{
    ModelImpl m;

    SystemImpl pop1(100, "pop1");
    SystemImpl pop2(0, "pop2");

    FlowExp exponential(&pop1, &pop2, "exponential");

    m.add(&pop1);
    m.add(&pop2);
    m.add(&exponential);

    m.run(0, 100);

    m.showResults();

    assert(fabs(pop1.getEnergy() - 36.6032) <= 0.0001);
    assert(fabs(pop2.getEnergy() - 63.3968) <= 0.0001);
}

void logisticalFunctionalTest()
{
    ModelImpl m;

    SystemImpl p1(100, "p1");
    SystemImpl p2(10, "p2");

    FlowLog logistical(&p1, &p2, "logistical");

    m.add(&p1);
    m.add(&p2);
    m.add(&logistical);

    m.run(0, 100);

    m.showResults();

    assert(fabs(p1.getEnergy() - 88.2167) <= 0.0001);
    assert(fabs(p2.getEnergy() - 21.7834) <= 0.0001);
}

void multiExponentialFunctionalTest()
{
    ModelImpl m;

    SystemImpl q1(100, "q1");
    SystemImpl q2(0, "q2");
    SystemImpl q3(100, "q3");
    SystemImpl q4(0, "q4");
    SystemImpl q5(0, "q5");
    FlowExp f(&q1, &q2, "f");
    FlowExp g(&q1, &q3, "g");
    FlowExp r(&q2, &q5, "r");
    FlowExp t(&q2, &q3, "t");
    FlowExp u(&q3, &q4, "u");
    FlowExp v(&q4, &q1, "v");

    m.add(&q1);
    m.add(&q2);
    m.add(&q3);
    m.add(&q4);
    m.add(&q5);

    m.add(&f);
    m.add(&g);
    m.add(&r);
    m.add(&t);
    m.add(&u);
    m.add(&v);

    m.run(0, 100);

    m.showResults();

    assert(fabs(q1.getEnergy() - 31.8513) <= 0.0001);
    assert(fabs(q2.getEnergy() - 18.4003) <= 0.0001);
    assert(fabs(q3.getEnergy() - 77.1143) <= 0.0001);
    assert(fabs(q4.getEnergy() - 56.1728) <= 0.0001);
    assert(fabs(q5.getEnergy() - 16.4612) <= 0.0001);
}
