//j1414 小林佳樹
#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"
#include "stack.h"
int main()
{
  int ch, pch, small;
  small = 0;//小文字で始まる単語の時は1にする
  init_stack(); //スタックの初期化
  fprintf(stdout,"Please enter English text: \n");
  pch = ' ';  //前に入力された文字
  //入力された英単語を処理する
  while((ch = getchar())!='\n')
  {
    if(ch != ' ')
    {
      //スペースでないときの処理を書く
      if(pch == ' ' && ch >= 0x61 && ch <= 0x7a)
        {
          push(ch);
          small = 1;
        }
      else if(small == 1)
        {
          push(ch);
        }
    }
    else
    {
      //スペースの時の処理を書く
    }
    pch = ch;
  }
  while(stack_stock()>0)
  {
    fprintf(stdout,"%c",pop());
  }
  fprintf(stdout,"\n");
}
