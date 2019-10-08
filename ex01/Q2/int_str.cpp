#include <iostream>
#include <cstdlib>
#include "int_str.h"

/* mallocを使用して文字列にメモリを割り当てる */
char* intToStr(int digit)
{
  // 桁数を計算
  int n   = 0;
  int tmp = digit;
  while( tmp != 0 )
  {
    tmp /= 10;
    ++n;
  }
  // 符号が負の場合
  bool flag = false;
  if( digit < 0){
    flag = true;
    ++n;
    digit = digit * -1;
  }

  // str -> int は '0' を引くなら、足せばいい
  char* res = static_cast< char* >( malloc( sizeof(char) * ( n + 1 ) ) );
  for(int i = 1; i < n; ++i )
  {
    if( flag == true ) res[0] = '-';
    res[n-i] = digit % 10 + '0'; // 現在の数字を抽出
    digit /= 10; // 次の数字へ
  }
  res[n] = '\0'; // 忘れずに
  return res;
}

/* char* は有効な符号付き整数を表す */
int strToInt(const char* str)
{
  int i=0; //
  bool flag = false;
  // 負の数を受け取った場合
  if(str[0] == '-'){
   flag = true;
   i++;
  }

  int digit = 0;
  for( ; str[i] != '\0'; ++i )
  {
    digit += ( str[i] - '0' );
    digit *= 10; // 最後の文字を十倍すると大きくなりすぎるからループ抜けたら10で割る
  }
  digit /= 10; // 次の数字へ

  if( flag ==true ){
    return digit * -1;
  }else return digit;
}
