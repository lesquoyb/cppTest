cppTest
=======
#Installation#
Pour installer cppTest, il suffit d'inclure les fichiers cpptest.h et cpptesttools.h à votre projet courant. Vous pouvez aussi inclure le fichier cpptestfacade.h, mais ce dernier n'est pas strictement necessaire.
#Utilisation basique#
Créer un test unitaire(ou une série de tests unitaire) est très simple. Une fois les headers importés il vous suffira de créer un nouveau header ('demoUnit.h' dans cet exemple) et d'y inclure "cpptest.h".
Un ensemble de tests unitaire se décompose comme ceci:
```
déclaration de l'ensemble de tests
	suite de tests
fin de l'ensemble de tests
```
Plus concrètement on déclarera un ensemble de tests avec l'expression "CPPTEST(nom)" où nom est le nom de l'ensemble de test, chaque test est déclaré avec l'expression "TESTCASE(nom,fonction);" où nom est le nom du test et fonction est le corp du test( plus de détail dans la partie corp de test).
Un exemple d'une vraie déclaration d'un ensemble de test:
```
#ifndef DEMOTEST1_H
#define DEMOTEST1_H
#include "cpptest.h"
CPPTEST(DemoTest1)
	TESTCASE(UnEgalUn,{
		equals(1,1);
	});
ENDTEST
#endif
```
Facile non ?

#Corp de test#
Vous avez peut être remarqué dans l'exemple précédent que la fonction TESTCASE avait une syntaxe inhabituelle. En effet, la syntaxe de ces tests veut que les accolades du corp d'un test soient toujours présente afin de rester rapidement repérable. En se qui concerne l'utilisation même d'un test, il n'est évidemment pas restreint à une ligne (même si la norme des tests unitaire veut qu'ils soient le plus succint possible) et vous pouvez y faire absolument tous ce que vous faites dans une fonction normale comme  déclarer des variables mettre des conditions ou des boucles. La seul contrainte est que vous devez absoluement renvoyer un booléen (true si le test réussi, false sinon), ou utiliser les fonctions déjà écrites(comme le "equals" utilisé un peu plus haut) qui se chargent de le faire pour vous.   
##Utilisation de variables communes à tous les tests##
Quand on écrit un ensemble de tests cohérents, on a souvent besoin d'utiliser dans plusieurs tests les mêmes variables. Par exemple si vous écrivez un ensemble de tests afin de vérifier le bon fonctionnement de transformations géométriques, il y a des chances que vous ayez à plusieurs reprises besoin d'utiliser le point d'origine du plan. Afin d'éviter la repetition de code, il est possible de déclarer des variables dans le corp de l'ensemble de test et de les appeler simplement par leur nom dans les tests. Il faudra néanmoins déclarer les variables avant les tests qui les utilisent. Un petit exemple concret:
```
#ifndef DEMOTEST1_H
#define DEMOTEST1_H
#include "cpptest.h"
#include "point.h"

CPPTEST(Demo1)
	
	Point origine(0,0);
	Point un(1,1);

	TESTCASE(Translation,{
    		equals(origine.translation(un),un);
 	});

	TESTCASE(TranslationFausse,{
    		nEquals(origine.translation(un),origine);
 	});

ENDTEST

#endif 
```

#Fonctions disponibles#
Au cours des exemple précédents, vous avez pu constater que je n'utilisais pas le mot clef return dans mes tests alors qu'ils ne peuvent fonctionner que s'ils renvoient un booléen.
C'est parce que j'utilise des fonctions déjà construite qui s'en chargent pour moi. Un petit tour des fonctions disponible s'impose donc.
##Les fonctions de déclarations##
Elles ont déjà été abordée précédemment, mais il me semblait important de préciser que leur paramètre "nom" était écrit tel quel, en texte brut, sans guillemets autour. De plus elles ne sont pas suivies d'un point virgule.
Liste des fonctions de déclarations:
*CPPTEST(nom): déclare un ensemble de test "nom"
*ENDTEST: fin de l'ensemble de test
*TESTCASE(nom,function): déclare un test "nom" exécutant la fonction "function".
*TESTLAUNCHER(nom): déclare une façade "nom"
*ENDLAUNCHER: fin de la façade.
##Les fonctions à utiliser dans un corp de test##
Ces fonctions sont divisée en deux groupes, celles avec debug et celles sans. Les fonctions avec debug font exactement la même chose que celles sans, sauf qu'elles affichent les valeurs des arguments dans le cas où le test échoue, ce sont donc les fonctions par défaut. Néanmoins ces fonctions necessitent que vous ayez surchargé l'operateur "<<" de vos arguments (ou que ce soit des types simple), ce qui n'est pas toujours le cas, c'est pourquoi leurs équivalent existent sans debug. Les fonctions sans debug ont le même nom que celles avec à ceci près qu'elles sont suivies de "ND" pour "No Debug"(exemple "equals"=>"equalsND").
Les fonctions ND ne seront donc pas détaillées puisqu'elles ont le même fonctionnement que les normales.
Les fonctions disponibles sont donc:
* equals(arg1,arg2): compare arg1 et arg2 et retourne true s'ils sont égaux, necessite donc d'avoir surchagé l'opérateur == .
* nEquals(arg1,arg2): compare arg1 et arg2 et retourne true s'ils ne sont pas égaux, necessite donc d'avoir surchargé l'opérateur == .
* diff(arg1,arg2): compare arg1 et arg2 et retourne true s'ils sont différent, le test est fait à l'aide de l'operateur != .
* errorExpected(func): execute la fonction func et retourne true si une erreur a été levée, false sinon. Il n'y a pas de debug pour cette fonction. La fonction func doit être entre accolades.

À noter: 

* Ces fonctions stoppent l'execution de votre test, ne mettez donc pas de code en dessous car il ne sera pas executé.
* Ces fonctions doivent être suivies d'un point virgule.

#Faire une façade#
Lorsque vous créez plusieurs ensembles de tests, il n'est pas conseillé de les executer à la suite dans votre programme principal. Au lieu de ça on peut créer une façade se chargeant de le faire tout en étant plus lisible et facilement maintenable. Pour ce faire il suffira de créer un nouveau fichier d'entête, d'y inclure "testfacade.h" ainsi que les headers des ensembles de tests à lancer et de proceder comme suis:
// déclaration de la façade
	// ajout des test
// fin de la façade
plus concretement si on voulait créer une façade pour lancer les tests de l'ensemble Demo1 créé un peu plus tôt cela donnerai:
```
#ifndef DEMOLAUNCHER_H
#define DEMOLAUNCHER_H
#include "cpptestfacade.h"
#include "demotest1.h"

TESTLAUNCHER(demoLauncher1)

    addTest(new Demo1());

ENDLAUNCHER

#endif // DEMOLAUNCHER_H
```
Une façade possède deux méthodes: addTest(test) qui prend un pointeur sur un ensemble de tests à effectuer, et de la méthode run, à appeler dans votre programme principal qui permet de lancer tous les tests. 
On peut maintenant lancer les tests ainsi:
```
#include "demolauncher.h"

int main(){
    demoLauncher1 l;
    l.run();
}

```
Ce programme retourne le résultat suivant:
```
Demo1:
# Translation réussie
# TranslationFausse réussie
il n'y a pas d'erreur
==========================
il n'y a pas d'erreur dans l'ensemble des tests
```
Et voilà vous avez une batterie de test facilement modifiable qui se lance en deux lignes. 
#Exemple complet#

#Problèmes pouvant survenir#
##function is not a member of std##

##Nombre dans le nom de fonction##
