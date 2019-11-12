#include <iostream>
#include <cstring>
#include <stack>
#include <sstream>

using namespace std;

int eval(const string numStr){
  int second;
  int first;

  stringstream ss(numStr);
  stack<int> st;
  string s;


  while(ss >> s){

    if (s == "+") {
      second = st.top();
      st.pop();
      first = st.top();
      st.pop();
      st.push(first + second);
    }
    else if  (s == "-") {
      second = st.top();
      st.pop();
      first = st.top();
      st.pop();
      st.push(first - second);
    }
    else if  (s == "*") {
      second = st.top();
      st.pop();
      first = st.top();
      st.pop();
      st.push(first * second);
    }
    else  if  (s == "/") {
      second = st.top();
      st.pop();
      first = st.top();
      st.pop();
      st.push(first / second);
    }
    else{
      st.push(stoi(s));
    }
  }
  return st.top();
}


int main (){
  string numStr = "1 2 + 3 4 - *";

  cout << eval(numStr) << endl;
  return 0;
}
