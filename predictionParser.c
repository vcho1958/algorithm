#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void match(char token);
void term();
void factor();
void rest();
void rest2();
void expr();
char nexttoken();

char lookahead;

int main(){
  lookahead = nexttoken();
  expr();
  if (lookahead == '$')
    printf("\n");
  else
  printf(" error\n");
}

void expr(){
  term(); 
  putchar('3'); 
  rest();
}

void match(char token) {
  if (lookahead == token)
    lookahead = nexttoken();
  else {
    printf("error\n");
    exit(1);
  }
}

void rest(){
    if(lookahead == '+'){
      match('+'); term();  putchar('1'); rest(); 
    }
    else if(lookahead == '-'){
      match('-'); term();  putchar('2'); rest(); 
    }
}

void term(){
  factor();
  putchar('6'); 
  rest2(); 
  
}


void rest2(){
  switch(lookahead){
    case '*':
      match('*'); factor(); putchar('4'); rest2();
      break;
    case '/':
      match('/'); factor(); putchar('5'); rest2();
      break;
  }
}

void factor(){
  if(lookahead == '('){
    match('('); expr(); match(')'); 
    putchar('7');
  }else if(isdigit(lookahead)){
    match(lookahead);
    
  }else{
    printf("error\n");
    exit(1);
  }
  
}

char nexttoken() {
  char c;
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0') continue;
    return(c);
  }
}

