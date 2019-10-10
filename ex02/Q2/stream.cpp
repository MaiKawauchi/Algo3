#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int lines = 5;
  double data[lines][2];

  // input data
  for(int i=0; i<lines; ++i){
    for(int j=0; j<2; ++j){
      cin >> data[i][j];
    }
  }

  cout << "---------------------+---------------------+---------------------" << endl;
  for(int i=0; i<lines; ++i){
    cout << setw(20) << i+1 << " |";
    cout << setw(20) << data[i][0] << " |";
    cout << setw(20) << data[i][1] << endl;
  }
}
