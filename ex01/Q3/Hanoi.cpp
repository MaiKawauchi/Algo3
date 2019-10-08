// Hanoi.cpp
#include <iostream>
#include <string>

// COMPLETE:
// Define the function Hanoi. 
// Its argument is the number of disks.
//
// The function should print a series of instructions for 
// how to move the disks in order to solve the problem. 

int main(int argc, char** argv) {
  if (argc!=2) {
    std::cout << "Usage: " << argv[0] << " n" << std::endl;
    std::cout << "where n is the number of disks." << std::endl;
    return 1;
  }

  int n = std::stoi(argv[1]); // convert the argv[1] to an int

  // COMPLETE:
  // Call Hanoi with n disks
}
