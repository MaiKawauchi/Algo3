#include <cstring>
#include <iostream>
#include <cmath>
#include "Mat_NxN.h"

using namespace std;

// copy constructor(one argument)
Mat_NxN::Mat_NxN(const Mat_NxN& mat){
  memcpy(&dat[0][0], &mat, sizeof(T)*N*N);
}

// defoult constructor
Mat_NxN::Mat_NxN() {
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      dat[i][j] = 0.0;
      if(i == j) dat[i][j] = 1.0;
    }
  }
}

Mat_NxN::Mat_NxN(const T coefficients[N][N]){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      dat[i][j] = coefficients[i][j];
    }
  }
}

// destructor
Mat_NxN::~Mat_NxN(){}

/*------------------- 代入演算子 ------------------- */
Mat_NxN& Mat_NxN::operator= (const Mat_NxN& mat) &{
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        dat[i][j] = mat.dat[i][j];
      }
    }
    return *this;
}

Mat_NxN& Mat_NxN::operator= (Mat_NxN&& mat) & noexcept{
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      dat[i][j] = std::move(mat.dat[i][j]);
    }
  }
  return *this;
}

/*--------------- 行列の各要素を参照 --------------- */
T& Mat_NxN::operator() (int i, int j){
  return dat[i][j];
}

T Mat_NxN::operator() (int i, int j) const{
  return dat[i][j];
}


/*----------------- 複合代入演算子 ----------------- */
/*-------------------- 複合加算 -------------------- */

Mat_NxN& Mat_NxN::operator+= (const Mat_NxN &mat){
for(int i=0; i<N; ++i){
  for(int j=0; j<N; ++j){
    dat[i][j] = dat[i][j] + mat.dat[i][j];
  }
 }
 return *this;
}

/*-------------------- 複合減算 -------------------- */
Mat_NxN& Mat_NxN::operator-= (const Mat_NxN &mat){
for(int i=0; i<N; ++i){
  for(int j=0; j<N; ++j){
    dat[i][j] = dat[i][j] - mat.dat[i][j];
  }
 }
 return *this;
}

/*-------------------- 複合乗算 -------------------- */
Mat_NxN& Mat_NxN::operator*= (const Mat_NxN &mat){
  Mat_NxN c = *this;
for(int i=0; i<N; ++i){
  for(int j=0; j<N; ++j){
    dat[i][j] = 0.0;
    for (int k=0; k<N; ++k) {
      dat[i][j] += c.dat[i][k] * mat.dat[k][j];
    }
  }
 }
 return *this;
}


/*------------------- 単項マイナス ------------------- */
// B = -A
Mat_NxN Mat_NxN:::operator- () const{
  Mat_NxN Nega;
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      if(dat[i][j] != 0){
        Nega.dat[i][j] = -dat[i][j];
      }
    }
  }
  return Nega.dat;
}







/*-------------------- 算術演算子 --------------------- */
/*-------------------- 行列加算(+) -------------------- */

Mat_NxN operator+ (const Mat_NxN& matA, const Mat_NxN& matB){
  return Mat_NxN<T, N>(matA) += matB;
}
/*-------------------- 行列減算(-) -------------------- */

Mat_NxN<T, N> operator- (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB){
  return Mat_NxN<T, N>(matA) -= matB;
}
/*-------------------- 行列乗算(x) -------------------- */

Mat_NxN<T, N> operator* (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB){
  return Mat_NxN<T, N>(matA) *= matB;
}



/*------------------- 等価比較演算子 --------------------*/

bool operator== (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB) {
  for(int i=0; i< N; ++i){
    for(int j=0; j<N; ++j){

      if( matA(i, j) != matB(i, j) ) return false;
    }
  }
  return true;
}
