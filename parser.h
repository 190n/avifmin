#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdbool.h>
#include <stdio.h>

typedef struct Parser Parser;

//
// Allocate a new Parser
//
// fd: the open file to be parsed
//
// returns NULL if allocation failed
//
Parser *parser_create(FILE *fd);

//
// Delete a Parser
//
// p: double pointer to the Parser, so the pointer is set to NULL
//
void parser_delete(Parser **p);

//
// Returns whether a Parser has reached the end of its file
//
// p: pointer to the Parser
//
bool parser_done(Parser *p);

#endif
