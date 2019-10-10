// Hanoi.cpp

#include <iostream>
#include <cstring>

// COMPLETE:
// Define the function Hanoi.
// Its argument is the number of disks.
//
// The function should print a series of instructions for
// how to move the disks in order to solve the problem.

void Hanoi(int n, std::string from, std::string to, std::string work)
{
  static unsigned int count = 0;
  if(n == 1){
    std::cout << ++count << ": " << from << " to " << to << std::endl;
  }else{
    Hanoi(n-1, from, work, to);
    std::cout << ++count << ": " << from << " to " << to << std::endl;
    Hanoi(n-1, work, to, from);
  }

}




int main(int argc, char** argv)
{
  // Input the circle count
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " n" << std::endl;
    std::cout << "where n is the number of disks." << std::endl;
    return 1;
  }

  const std::string FROM = "A";
  const std::string WORK = "B";
  const std::string TO   = "C";

  int n = std::stoi(argv[1]); // convert the argv[1] to an int

  // COMPLETE:
  // Call Hanoi with n disks
  Hanoi(n, FROM, TO, WORK);
}
