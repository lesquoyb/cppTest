#ifndef DEMOTEST1_H
#define DEMOTEST1_H
#include "cpptest.h"

CPPTEST(Demo1)

TESTCASE(UnEgalUn,{
    equals(1,1);
 });

TESTCASE(UnNonEgalDeux,{
    nEquals(1,2);
 });

ENDTEST

#endif // DEMOTEST1_H
