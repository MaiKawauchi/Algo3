#include <iostream>
#include <cstring>
#include <stack>
#include <sstream>


using namespace std;


int eval(string numStr){
  std::istringstream ss;
  ss = std::istringstream(numStr);
  int num = atoi(numStr.c_str());
  ss >> num;
  return num;
}


int main (){
  std::stack<int> st;

  std::string numStr;
  std::string n_tmp;
  std::string n_first;
  int num;
  int second;
  int first;

  cin >> numStr;

  for(int i=0; i<(int)(numStr.length()); ++i){
    n_tmp = numStr[i];
    n_first = numStr[i-1];

    if('9' >= numStr[i] && numStr[i] >= '1')
      {
        num = eval(n_tmp);
        st.push(num);
      }
    else{
      if (numStr[i] == '+') {
        second = st.top();
        st.pop();
        first = st.top();
        st.pop();
        st.push(first + second);
      }
      else if  (numStr[i] == '-') {
        second = st.top();
        st.pop();
        first = st.top();
        st.pop();
        st.push(first - second);
      }
      else if  (numStr[i] == '*'){
        second = st.top();
        st.pop();
        first = st.top();
        st.pop();
        st.push(first * second);
      }
      else  if  (numStr[i] == '/'){
        second = st.top();
        st.pop();
        first = st.top();
        st.pop();
        st.push(first / second);
      }
    }
  }
  cout << st.top() << endl;
  return 0;
}
