#include "parser.h"


Token *parse(char *input,const char discriminate){
  size_t n;
  char *p,*lp;

  input = strip(input);
  p = lp = input;

  Token *start;
  Token *curr = start = NULL;

  while(*p != '\0'){
    if(*p == discriminate){

      Token *t = calloc(1,sizeof(Token));
      if(!t) exit(EXIT_FALIURE);
      t->size = n;
      t->next = NULL;

      char *t_value = malloc((n + 1) * sizeof(char));
      if(!t_value) exit(EXIT_FALIURE);

      char *tp;
      for(tp = t_value;lp <= (p - 1);lp++,tp++){
        *tp = *lp;
      }

      *tp = '\0';
      if(!start){
        start = token;
        curr = start;
      }else{
        curr->next = token;
        curr = token;
      }

      n = 0;
    }else{n++;}
    p++;
  }
  return start;

}

char *strip(char *input){
  int s = 0;
  while (input[s] != '\0' && input[s] == ' ') s++;
  char *stripped_str = calloc((strlen(input) - s) + 1,sizeof(char));
  strcpy(stripped_str,input + s);
  return stripped_str;
}
