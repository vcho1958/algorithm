#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void diagram();
char lookahead;
int state = 1;

int main(){
  diagram();
}

void error(char c){
  printf("invalid char '%c'", c);
  exit(1);
}


void diagram()
{
  char c;
  while(1) {
    switch(state) {
      case 1: 
        c = getchar();
        switch(c){
          case 'i':
            state = 2;
            break;
          case 'f':
            state = 11;
            break;
          default:
            if(isalpha(c))
              state = 15;
            else
              state = 8;
        }
        break;
      case 2:
        c = getchar();
        switch(c){
          case 'n':
            state = 3;
            break;
          case 'f':
            state = 9;
            break;
          default:
            if(isalpha(c) || isdigit(c))
              state = 15;
            else
              state = 8;
          }
        break;
      case 3:
        c = getchar();
        switch(c){
          case 't':
            state = 4;
            break;
          default:
            if(isalpha(c) || isdigit(c))
              state = 15;
            else  state = 8;
        }
        break;
      case 4:
        c = getchar();
        if(isalpha(c) || isdigit(c))
          state = 15;
        else
            state = 5;
        break;
      case 5:
        printf("3");
        state = 6;
        break;
      case 6:
        if(isblank(c) || c == '\n')
          return;
        else
          state = 8;
        break;
      case 8:
        error(c);
        break;
      case 9:
        c = getchar();
        if(isalpha(c) || isdigit(c))
          state = 15;
        else state = 10;
        break;
      case 10:
        printf("2");
        state = 6;
        break;
      case 11:
          c = getchar();
        switch(c){
          case 'o':
            state = 12;
            break;
          default:
            if(isalpha(c) || isdigit(c))
              state = 15;
            else state = 8;
        }
        break;
      case 12:
          c = getchar();
        switch(c){
          case 'r':
            state = 13;
            break;
          default:
            if(isalpha(c) || isdigit(c))
              state = 15;
            else state = 8;
        }
        break;      
      case 13:
        if(isalpha(c) || isdigit(c))
          state = 15;
        else state = 14;
        break; 
      case 14:
        printf("1");
        state = 6;
        break;
      case 15:
        c = getchar();    
        if(isalpha(c) || isdigit(c))
          state = 15;
        else
          state = 16;
        break;
      case 16:
        printf("9");
        state = 6;
        break;
    }
  }
}