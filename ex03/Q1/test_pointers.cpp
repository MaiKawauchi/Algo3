// test_pointers.cpp
// COMPLETE include necessary headers
#include <iostream>

int main(void)
{
  // 1. declare a variable d as a pointer to a double
  double* d;

  // 2. create a double variable named pi, and store the value 3.14159
  double pi = 3.14159;

  // 3. make d points to pi
  d = &pi;

  // 4. print out the content of the memory location pointed to by d
  std::cout << "* memory location point d " << std::endl;
  std::cout << *d << std::endl << std::endl;



  /*----------------------------------------------------------------------------------*/
  int a[5] = {1, 2, 3, 4, 5};
  // 5. declare a variable ip as a pointer to an int
  int* ip;

  // 6. make ip points to the beginning of the array a
  ip = &a[0];

  // 7. print out what ip points to and the content of a[0] (verify they are the same)
  std::cout << "ip  : " <<  *ip << std::endl;
  std::cout << "a[0]: " << a[0] << std::endl << std::endl;

  // 8. increase ip by 3 and check that what it points to corresponds to a[3]
  ip = ip+3;
  std::cout << "ip  : " << *ip << std::endl;
  std::cout << "a[3]: " << a[3] << std::endl << std::endl;

  // 9. make ip points to the last element of the array by increasing it by 1
  //     and check that what it points to corresponds to a[4]
  ip=ip+1;
  std::cout << "ip  : " << *ip << std::endl;
  std::cout << "a[3]: " << a[4] << std::endl << std::endl;



  /*---------------------------------------------------------------------------------*/
  int n = 10;
  // 10. declare a variable "f" as a pointer to float and
  // make it point to an array of "n" element of type "float" created on the heap
  float* f;
  f =new float[n];

  // 11. store in each f[i] (for i=0 to n-1) the value float(i) / 5.0f;
  for(int i=0; i<n-1; ++i) {
   f[i] = i / 5.0f;
  }


  // 12. print out each element of f
  std::cout << "* value float(i) / 5.0f" << std::endl;
  for(int i=0; i<n-1; ++i) {
   std::cout << f[i] << std::endl;
  }
  std::cout << std::endl;

  // 13. delete the previously allocated memory
  delete[]f;



  /*---------------------------------------------------------------------------------*/
  int m = 5;
  double** dd;
  // 14. allocate memory for a 2d array of size m * n on the heap
  //(i.e. m arrays of size n). Make dd points to this 2d array.
  dd = new double*[m];
  for(int i=0; i<m; ++i) dd[i] = new double[n];

  // 15. set the element dd[i][j] to be equal to i*j/2
  for(int i=0; i<m; ++i){
    for(int j=0; j<n; ++j){
      dd[i][j] = (double)(i*j/2.0);
      std::cout << dd[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // 16. delete the memory allocated for the 2d array
  for(int i=0; i<m; ++i) delete[]dd[i];
  delete[]dd;

  return 0;
}
