// test_ArrayStack.cpp
#include "ArrayStack.h"

int main(void)
{
  /*------------------------------------------------------------*/
  /* stack1という名前のArrayStackのインスタンスを作成します     */
  /* デフォルトのコンストラクタを使用する                       */
  /* このスタックで1,2,3,4,5をプッシュ                          */
  /*------------------------------------------------------------*/
  std::cout << "stack1" << std::endl;
  ArrayStack stack1;
  for(int i=1; i<=5; i++) stack1.push(i);
  while(stack1.empty() != 1 ){
    stack1.pop();
  }


  /*------------------------------------------------------------*/
  /* stack2という名前のArrayStackの別のインスタンスを作成します */
  /* 他のコンストラクターを使用して、元のサイズ5を指定します    */
  /* このスタックで1,2、...、10をプッシュ                       */
  /*------------------------------------------------------------*/
  std::cout << "stack1" << std::endl;
  ArrayStack stack2(5);
  for(int i=1; i<=10; i++) stack2.push(i);
  while(stack2.empty() != 1 ){
    stack2.pop();
  }


return 0;
}
