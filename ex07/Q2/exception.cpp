// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;

void doSomeComputation() {
  throw std::runtime_error("failure during doing some computation");
}

void example() {
  FILE* logfile = fopen("logfile.txt", "w+");

  try{
    if (!logfile) throw std::runtime_error("failed to open file");
    fputs("log1", logfile);
  }catch(const std::runtime_error& error){
    cout << error.what() << endl;
    fclose(logfile);
    throw;
  }


  // call a function that performs some computation and may throw
  // an exception
  try{
    doSomeComputation();
  }
   catch(const std::runtime_error& error){
     cout << error.what() << endl;
     fclose(logfile);
     throw;
    }


  /*------------------------------------------------*/
  cout << "closing logfile" << endl;
  fclose(logfile);
  /*------------------------------------------------*/
}



int main(void) {
  cout << "Calling example()" << endl;

  try{
    example();
  }catch(const std::runtime_error& error){
    cout << error.what() << endl;
  }

  cout << "After calling example()" << endl;
  return 0;
}
