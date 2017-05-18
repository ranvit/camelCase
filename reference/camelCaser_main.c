#include <stdio.h>
#include <stdlib.h>
#include "camelCaser.h"

void print_output(char **output){
    printf("Got the following:\n");
    if(output){
        char ** line = output;
        while(*line){
            printf("\t'%s'\n", *line);
            line++;
        }
    } else{
        printf("NULL POINTER!\n");
    }
    printf("-----------------------------------------------------------------------------------------\n");
}

void print_input(char * input){
    printf("testing: \n\t'%s'\n\n", input);
}

int main() {
/*    char * inputs[] = {
        "Hello World.",
        "The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.",
        NULL
    };

    char ** input = inputs;
    while(*input){
        print_input(*input);
        char **output = camel_caser(*input);
        print_output(output);
        input++;
    }
*/

	char ** output;
	output = camel_caser("The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.");
	print_output(output);
	output = camel_caser(NULL);
	print_output(output);
	output = camel_caser("1two 3four 5six 7eight 9ten.");
	print_output(output);
	output = camel_caser("Hello World  . m ...");
	print_output(output);
	output = camel_caser("No punct. memes");
	print_output(output);
	output = camel_caser("Hey Let's camelCase.");
	print_output(output);
	output = camel_caser("Hello World.");
	print_output(output);
	output = camel_caser("No Period");
	print_output(output);

    return 0;
}
