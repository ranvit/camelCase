/**
 * Chatroom Lab
 * CS 241 - Fall 2016
 */
#include "camelCaser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char **strsplit(const char *str, const char *delim, size_t *numtokens);
void free_args(char **args);
void myUpper(char * param);

char **camel_caser(const char *input_str) {

	if(!input_str) return NULL;

	char * input_copy = malloc(strlen(input_str) + 1);
	strcpy(input_copy, input_str);

	for(int i = 0; input_copy[i]; i++){
		input_copy[i] = tolower(input_copy[i]);
		if(ispunct(input_copy[i])){
			input_copy[i] = '*';
		}
		if(isspace(input_copy[i])){
			input_copy[i] = '#';
		}
	}
//	printf("%s\n\n", input_copy);

	char * token;
	const char s[2] = "#";

	const char * delim = "*";
	size_t numtokens = 0;
	char ** splitted = strsplit(input_copy, delim, &numtokens);
//	printf("%d\n", (int)numtokens);

//	char ** taco = malloc(sizeof(char *) * (numtokens+1));
	char ** taco = calloc((numtokens+1), sizeof(char *));

/*
	char ** iter = splitted;
	while(*iter){
		printf("%s\n", *iter);
		iter++;
	}
	if(*iter == NULL) printf("NULL!\n");
*/
	char ** temp = splitted;

	int f = 0;
	int j = 0;
	while(*temp){
		j = 0;
//		taco[f] = malloc(strlen(*temp) + 2);
		taco[f] = calloc(strlen(*temp) + 2, sizeof(char));
		token = strtok(*temp, s);
		while(token){
//			printf("%s", token);
			if(j == 0) strcpy(taco[f], token);
			else strcat(taco[f], token);
			token = strtok(NULL, s);
//			if(token) *token = toupper(*token);
			if(token) myUpper(token);
			j++;
		}
//		printf("\n");
		temp++; f++;
	}
	taco[f] = NULL;
//	if(!ispunct(input_str[strlen(input_str)-1])) taco[f-1] = NULL;
//	printf("[");

	temp = taco;
	while(*temp){
//		printf("\"%s\",\n", *temp);
//		free(*temp);
		temp++;
	}
//	if(*temp == NULL) printf("NULL]\n");
//	free(taco);
	free_args(splitted);
	free(input_copy);
	return taco;
}

void myUpper(char * param){

	char * lol = param;
	while(*lol){
		if(isalpha(*lol)){
			*lol = toupper(*lol);
			break;
		}
		lol++;
	}
	return;
}

char **strsplit(const char *str, const char *delim, size_t *numtokens) {
  // copy the original string so that we don't overwrite parts of it
  // (don't do this if you don't need to keep the old line,
  // as this is less efficient)
  char *s = strdup(str);
	char * s_temp = s;
  // these three variables are part of a very common idiom to
  // implement a dynamically-growing array
  size_t tokens_alloc = 1;
  size_t tokens_used = 0;
  char **tokens = calloc(tokens_alloc, sizeof(char *));
//  char *token, *strtok_ctx;
	char * token, *curr;
//  for (token = strtok_r(s, delim, &strtok_ctx); token != NULL;
//       token = strtok_r(NULL, delim, &strtok_ctx)) {
//  for (token = strsep(&s, delim); token != NULL;
//       token = strsep(&s, delim)) {
	//printf("\nlast thing is %s\n", token);

	token = strsep(&s, delim);
	while(1){
		curr = strsep(&s, delim);
		if(!curr) break;

    // check if we need to allocate more space for tokens
    if (tokens_used == tokens_alloc) {
      tokens_alloc *= 2;
      tokens = realloc(tokens, tokens_alloc * sizeof(char *));
    }
    tokens[tokens_used++] = strdup(token);

		token = curr;
  }
  // cleanup
  if (tokens_used == 0) {
    free(tokens);
    tokens = NULL;
  } else {
    tokens = realloc(tokens, tokens_used * sizeof(char *));
  }
  *numtokens = tokens_used;
  free(s_temp);
  // Adding a null terminator
  tokens = realloc(tokens, sizeof(char *) * (tokens_used + 1));
  tokens[tokens_used] = NULL;
  return tokens;
}

void free_args(char **args) {
  char **ptr = args;
  while (*ptr) {
    free(*ptr);
    ptr++;
  }
  free(args);
}
