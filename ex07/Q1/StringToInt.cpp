// stringToInt.cpp
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int stringToInt(const string& input) {
  stringstream instream;
  instream << input;
  int number;
  instream >> number;

  if (instream.fail()) {
    // Error: the input can not be converted
    throw std::invalid_argument("input can not be converted to an int");
  }

  char left;
  instream >> left;
  if (!instream.fail()) {
    // Error: there are some characters left after the int
    throw std::invalid_argument("input can not be converted to an int");
  }

  // everything went fine: returns the int
  return number;
}


int main(void) {
  try{
    string test1 = "11";
    cout << stringToInt(test1) << endl;
  }catch(const invalid_argument& error1){ // 不正な引数を示す
    cout << error1.what() << endl;        //  what（）はエラーの内容を返す
  }

  try{
  string test2 = "cc11";
  cout << stringToInt(test2) << endl;
  }catch(const invalid_argument& error2){
    cout << error2.what() << endl;
  }

  try{
    string test3 = "11cc";
    cout << stringToInt(test3) << endl;
  }catch(const invalid_argument& error3){
    cout << error3.what() << endl;
  }

  cout << "Tests passed" << endl;

  return 0;
}
