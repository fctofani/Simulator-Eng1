#include <iostream>
#include <cassert>

#include "functional.h"
#include "unitary.h"

using namespace std;

int main()
{
    exponentialFunctionalTest();
    logisticalFunctionalTest();
    multiExponentialFunctionalTest();

    systemUnitaryTests();
    flowUnitaryTests();
    modelUnitaryTests();

    cout << endl << endl;
    return 0;
}
