//j1414 小林佳樹
#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"
#include "stack.h"
int main()
{
  int ch, pch, small, i;
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
      if(pch == ' ' && ch >= 0x61 && ch <= 0x7a)  //前の文字がスペースでその文字が小文字の時
      {
        push(ch);                                 //その文字をスタックに格納
        small = 1;
      }
      else if(small == 1)                         //その文字が小文字から始まる英単語ならその文字をスタックに格納
      {
        push(ch);
      }
      else                                        //それ以外ならそのまま出力
      fprintf(stdout,"%c",ch);
    }
    else
    {
      if(small == 0)                              //スペースを押された時点で前の単語が大文字から始まる単語ならスペースを出力
        fprintf(stdout,"%c",ch);
      //スペースの時の処理を書く
      if(small == 1)                              //スペースを押された時点で前の単語が小文字から始まる単語ならスタックに保存してあるものを吐き出す
      {
        small = 0;
        while(stack_stock()>0)
        {
          printf("%c",pop());
        }
          fprintf(stdout," ");
      }
    }
    pch = ch;
  }
  while(stack_stock()>0)                            //enterが押された時点でスタックにあるものを全て吐き出す.
  {
    fprintf(stdout,"%c",pop());
  }
  fprintf(stdout,"\n");
}
