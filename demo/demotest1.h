#ifndef DEMOTEST1_H
#define DEMOTEST1_H

#include "../cpptest.h"
#include "point.h"
#include "vecteur.h"





CPPTEST(Demo1)

	Point origine(0.0,0.0);
	Point un(1,1);
	Vecteur vUn(1,1);

	TESTCASE(Translation,{
		    equals(origine.translation(vUn),un);
	});

	TESTCASE(TranslationFausse,{
		    nEquals(origine.translation(vUn),origine);
	});


ENDTEST

#endif // DEMOTEST1_H
