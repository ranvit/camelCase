/**
 * Chatroom Lab
 * CS 241 - Fall 2016
 */
#include "camelCaser_tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "camelCaser.h"

int arrayDiff(char ** output, char ** answer);

/*
 * Testing function for various implementations of camelCaser.
 *
 * @param  camelCaser   A pointer to the target camelCaser function.
 * @return              Correctness of the program (0 for wrong, 1 for correct).
 */
int test_camelCaser(char **(*camelCaser)(const char *)) {
  // TODO: Return 1 if the passed in function works properly; 0 if it doesn't.
//  return 1;
/*
	char * test1 = "Hey Let's camelCase.";
	char sol1[] = {"heyLet", "sCamelcase", NULL};

	char * test2 = "Hello World.";
	char sol2[] = {"helloWorld", NULL};

	char * test3 = "No Period";
	//char sol3[];
*/
/*
	camelCaser("The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.");

	camelCaser(NULL);

	camelCaser("1two 3four 5six 7eight 9ten.");

	camelCaser("Hello World  . m ...");

	camelCaser("No punct. memes");

	camelCaser("Hey Let's camelCase.");

	camelCaser("Hello World.");

	camelCaser("No Period");
*/

	char ** test1 = camelCaser("The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.");
	char * ans1[] = {"theHeisenbugIsAnIncredibleCreature", "facenovelServersGetTheirPowerFromItsIndeterminism", "codeSmellCanBeIgnoredWithIncredibleUseOfAirFreshener", "godObjectsAreTheNewReligion", NULL};

	if(arrayDiff(test1, ans1)) return 0;

	char ** ans2 = camelCaser(NULL);
	if(ans2 != NULL) return 0;


	char ** test3 = camelCaser("1two 3four 5six 7eight 9ten.");
	char * ans3[] = {"1two3Four5Six7Eight9Ten", NULL};

	if(arrayDiff(test3, ans3)) return 0;

	char ** test4 = camelCaser("Hello World  . m ...");
	char * ans4[] = {"helloWorld","m","","",NULL};

	if(arrayDiff(test4, ans4)) return 0;

	char ** test5 = camelCaser("No punct. memes");
	char * ans5[] = {"noPunct",NULL};

	if(arrayDiff(test5, ans5)) return 0;

	char ** test6 = camelCaser("Hey Let's camelCase.");
	char * ans6[] = {"heyLet","sCamelcase",NULL};

	if(arrayDiff(test6, ans6)) return 0;

	char ** test7 = camelCaser("Hello World.");
	char * ans7[] = {"helloWorld",NULL};

	if(arrayDiff(test7, ans7)) return 0;

	char ** test8 = camelCaser("No Period");
	char * ans8[] = {NULL};

	if(arrayDiff(test8, ans8)) return 0;

	return 1;
}

int arrayDiff(char ** output, char ** answer){
	char ** out = output;
	char ** ans = answer;

	if(out == NULL) if(ans != NULL) return 1;

	while(1){
		if(*out == NULL){
			if(*ans != NULL) return 1;
			else return 0;
		}

		if(strcmp(*out, *ans)!= 0) return 1;

		out++; ans++;
	}
}
