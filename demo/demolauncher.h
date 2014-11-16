#ifndef DEMOLAUNCHER_H
#define DEMOLAUNCHER_H
#include "../cpptestfacade.h"
#include "demotest1.h"

TESTLAUNCHER(demoLauncher1)

    addTest(new Demo1());

ENDLAUNCHER



#endif // DEMOLAUNCHER_H
