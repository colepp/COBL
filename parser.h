#ifndef PARSER_H

#include <string.h>

#define PARSER_H

typedef struct token  {
    char *value;
    size_t size;
    struct token *next;

} Token;

Token *parse(const char *input,const char discriminate);
char *strip(char *input);


#endif
