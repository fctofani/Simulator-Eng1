#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "system.h"

#include <string>
using namespace std;

/*! \class System (Implementation)
 * \brief System, which represents any component that can store something
 *
 * \details The system is a representation of any kind of element that is capable of storing energy, which might be a population, where it's energy is
 * represented by individuals on that population.
*/
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
