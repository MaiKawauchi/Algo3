//3では割り切れず,5で割り切れるすべての数値

#include <iostream>
#include <iterator>
#include <fstream>

int main()
{
  std::istream_iterator<int> isIt(std::cin);
  std::istream_iterator<int> isItEnd;
  std::ofstream outfile ("numbers.txt",std::ofstream::binary);
  std::ostream_iterator<int> isOut(outfile, " ");

  while(isIt != isItEnd){
    if(*isIt % 3 != 0 && *isIt % 5 == 0){
      *isOut = *isIt;
    }
    ++isIt;
  }

  return 0;
}
