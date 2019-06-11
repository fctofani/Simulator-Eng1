#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "system.h"

#include <string>
using namespace std;

class SystemImpl : public System
{
protected:
    double energy;
    string label;
public:
    SystemImpl();
    SystemImpl(double, string);
    SystemImpl(System*);
    double getEnergy() const;
    void setEnergy(double value);
    string getLabel() const;
    void setLabel(const string &value);

    virtual ~SystemImpl();

    SystemImpl& operator=(SystemImpl&);

    friend class UnitaryTestsSystem;
};

#endif // SYSTEMIMPL_H
