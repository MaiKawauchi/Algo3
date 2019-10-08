#ifndef int_str_h
#define int_str_h
#include "int_str.cpp"

/* mallocを使用して文字列にメモリを割り当てる */
char* intToStr(int digit);

/* char* は有効な符号付き整数を表す */
int strToInt(const char* str);

#endif
