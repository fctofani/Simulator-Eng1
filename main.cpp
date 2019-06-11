#include <iostream>
#include <cassert>

#include "functional.h"
#include "unitary.h"

using namespace std;

int main()
{
    systemUnitaryTests();
    flowUnitaryTests();
    modelUnitaryTests();

    exponentialFunctionalTest();
    logisticalFunctionalTest();
    multiExponentialFunctionalTest();

    cout << endl << endl;
    return 0;
}
