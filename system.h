#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

class System
{
public:
    virtual double getEnergy() const = 0;
    virtual void setEnergy(double) = 0;
    virtual string getLabel() const = 0;
    virtual void setLabel(const string&) = 0;
};

#endif // SYSTEM_H
