// test_ArrayStack.cpp
#include "ArrayStack.h"

int main(void)
{
  /*------------------------------------------------------------*/
  /* stack1という名前のArrayStackのインスタンスを作成します     */
  /* デフォルトのコンストラクタを使用する                       */
  /* このスタックで1,2,3,4,5をプッシュ                          */
  /*------------------------------------------------------------*/
  ArrayStack stack1;
  std::cout << "stack1" << std::endl;
  for(int i=1; i<=5; i++) stack1.push(i);
  while(stack1.empty() != 1 ){
    stack1.pop();
  }


  /*------------------------------------------------------------*/
  /* stack2という名前のArrayStackの別のインスタンスを作成します */
  /* 他のコンストラクターを使用して、元のサイズ5を指定します    */
  /* このスタックで1,2、...、10をプッシュ                       */
  /*------------------------------------------------------------*/

  ArrayStack stack2(5);
  std::cout << "stack2" << std::endl;
  for(int i=1; i<=10; i++) stack2.push(i);
  while(stack2.empty() != 1 ){
    stack2.pop();
  }

  /*------------------------------------------------------------*/
  // Copy Constructorを追加し、ArrayStackクラスの定義を完了。
  // Copy Constructorは、所有するデータ（つまり、ポインター）
  // を慎重に管理する必要がある。
  // Copy Constructorで「Copy Constructor」と表示される（情報の）行を追加
  //ファイル「ArrayStack.h」にCopy Constructorを直接追加できます。
  // Copy Constructorは、同じ型の引数を1つだけ持つConstructor
  /*------------------------------------------------------------*/

  ArrayStack stack3(stack1); // calls the default copy ctor
  std::cout << "stack3" << std::endl;

  ArrayStack stack4 = stack2; // calls the default copy ctor
  std::cout << "stack4" << std::endl;



  /*------------------------------------------------------------*/
  // 次に、ファイル「ArrayStack.h」を編集し、割り当て演算子の実装を追加。
  // 所有リソースを適切に管理し、自己割り当てを正しく処理するように注意。
  // 割り当て演算子で、「Assignment Operator」と表示される
  // （情報の）行も追加してください。
  /*------------------------------------------------------------*/
  ArrayStack stack5;
  std::cout << "stack5" << std::endl;
  stack5 = stack1;



  ArrayStack stack6(10);
  std::cout << "stack6" << std::endl;
  stack6 = stack6;


return 0;
}
