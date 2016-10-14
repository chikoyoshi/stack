//j1414 小林佳樹
#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"
#include "stack.h"
#define BUFLEN 100

int main()
{
  int ch, chst, err, i;
  char buf[BUFLEN];
  init_stack();           //スタックの初期化
  err = 0;
  i = 0;
  fprintf(stdout,"Please enter c program : \n");
  while(1)
  {
    fgets(buf, sizeof(buf), stdin);
    if(buf[1] == '\0')
    {
      if(stack_stock() <= 0 && err == 0) { fprintf(stdout, "Parentheses are correct !!\n"); }
      else{ fprintf(stdout, "Parentheses error !! \n");}
      break;
    }
    /*ここに括弧の整合性をチェックするプログラムを作成する                              */
    while(buf[i] == '\n'){
    	if(buf[i] == '[' || buf[i] == '{' || buf[i] == '(' || buf[i] == '<')
    		push(buf[i]);
    	else if(buf[i] == ']' || buf[i] == '}' || buf[i] == ')' || buf[i] == '>'){
    		ch = pop();
    		if(ch == '[' && buf[i] == ']')	continue;
    		else if (ch == '{' && buf[i] == '}') continue;
    		else if (ch == '(' && buf[i] == ')') continue;
    		else if (ch == '<' && buf[i] == '>') continue;
    		else err = 1;
    	}
    	i++;
    }
  }
}
