#ifndef PARSER_H

#include <string.h>

#define PARSER_H

typedef struct {
    char *value;
    size_t size;
} token;

token *parse(char *input,char discriminate);


#endif