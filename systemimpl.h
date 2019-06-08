#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <string>
using namespace std;

class SystemImpl
{
protected:
    double energy;
    string label;
public:
    SystemImpl();
    SystemImpl(double, string);
    double getEnergy() const;
    void setEnergy(double value);
    string getLabel() const;
    void setLabel(const string &value);

    virtual ~SystemImpl();
};

#endif // SYSTEMIMPL_H
