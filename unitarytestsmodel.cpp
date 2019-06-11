#include "unitarytestsmodel.h"
#include <cassert>
#include <cmath>

UnitaryTestsModel::UnitaryTestsModel()
{

}

short UnitaryTestsModel::UnitaryTestsGetName()
{
    ModelImpl m;
    m.name = "Test Model";
    assert(m.getName() == "Test Model");
    return 1;
}

short UnitaryTestsModel::UnitaryTestsSetName()
{
    ModelImpl m;
    m.setName("Model Test");
    assert(m.name == "Model Test");
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetStart()
{
    ModelImpl m;
    m.start = 100;
    assert(m.getStart() == 100);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsSetStart()
{
    ModelImpl m;
    m.setStart(-200);
    assert(m.start == 0);
    m.setStart(100);
    assert(m.start == 100);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetFinish()
{
    ModelImpl m;
    m.finish = 200;
    assert(m.getFinish() == 200);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsSetFinish()
{
    ModelImpl m;
    m.setFinish(-100);
    assert(m.finish == m.start);
    m.setFinish(200);
    assert(m.finish == 200);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetFlowContainer()
{
    std::list<FlowImpl*> l;
    ModelImpl m;
    m.flowContainer = l;
    assert(m.getFlowContainer() == l);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsSetFlowContainer()
{
    std::list<FlowImpl*> l;
    ModelImpl m;
    m.setFlowContainer(l);
    assert(m.flowContainer == l);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetSystemContainer()
{
    std::list<SystemImpl*> l;
    ModelImpl m;
    m.systemContainer = l;
    assert(m.getSystemContainer() == l);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsSetSystemContainer()
{
    std::list<SystemImpl*> l;
    ModelImpl m;
    m.setSystemContainer(l);
    assert(m.systemContainer == l);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetFlowContainerBegin()
{
    ModelImpl m;
    assert(m.getFlowContainerBegin() == m.flowContainer.begin());
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetFlowContainerEnd()
{
    ModelImpl m;
    assert(m.getFlowContainerEnd() == m.flowContainer.end());
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetSystemContainerBegin()
{
    ModelImpl m;
    assert(m.getSystemContainerBegin() == m.systemContainer.begin());
    return 1;
}

short UnitaryTestsModel::UnitaryTestsGetSystemContainerEnd()
{
    ModelImpl m;
    assert(m.getSystemContainerEnd() == m.systemContainer.end());
    return 1;
}

short UnitaryTestsModel::UnitaryTestsAddSystem()
{
    ModelImpl m;
    SystemImpl s;
    m.add(&s);
    std::list<SystemImpl*>::iterator it = m.systemContainer.begin();
    assert((*it) == &s);
    return 1;
}

short UnitaryTestsModel::UnitaryTestsAddFlow()
{
    class TestFlow : public FlowImpl{
        double execute(){return 0.01;}
    };

    ModelImpl m;
    TestFlow f;
    m.add(&f);
    std::list<FlowImpl*>::iterator it = m.flowContainer.begin();
    assert((*it) == &f);
    return 1;
}
