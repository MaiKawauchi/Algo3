
#include <cstring>
#include <iostream>
#include <cmath>
#include "Mat3x3.h"
#define MAT_SIZE 3

using namespace std;

// copy constructor(one argument)
Mat3x3::Mat3x3(const Mat3x3& mat){
  /*  if(!dat[0][0]) {
    cerr << "constructor Mat3x3(Mat3x3 &):Can not allocate memory.\n";
    exit(EXIT_FAILURE);
    }*/
  memcpy(&dat[0][0], &mat, sizeof(double)*3*3);
}
// defoult constructor
Mat3x3::Mat3x3() {
  dat[0][0] = 1.0;  dat[0][1] = 0.0;  dat[0][2] = 0.0;
  dat[1][0] = 0.0;  dat[1][1] = 1.0;  dat[1][2] = 0.0;
  dat[2][0] = 0.0;  dat[2][1] = 0.0;  dat[2][2] = 1.0;
}

Mat3x3::Mat3x3(const double coefficients[MAT_SIZE][MAT_SIZE]){
  for(int i = 0; i < MAT_SIZE; ++i){
    for(int j = 0; j < MAT_SIZE; ++j){
      dat[i][j] = coefficients[i][j];
    }
  }
}

// destructor
Mat3x3::~Mat3x3(){}

/*------------------- 代入演算子 ------------------- */
Mat3x3& Mat3x3::operator= (const Mat3x3 &mat) &{
    for(int i = 0; i < MAT_SIZE; ++i){
      for(int j = 0; j < MAT_SIZE; ++j){
        dat[i][j] = mat.dat[i][j];
      }
    }
    return *this;
}
Mat3x3& Mat3x3::operator= (Mat3x3&& mat) & noexcept{
  for(int i = 0; i < MAT_SIZE; ++i){
    for(int j = 0; j < MAT_SIZE; ++j){
      dat[i][j] = std::move(mat.dat[i][j]);
    }
  }
  return *this;
}

/*--------------- 行列の各要素を参照 --------------- */
double& Mat3x3::operator() (int i, int j){
  return dat[i][j];
}
double Mat3x3::operator() (int i, int j) const{
  return dat[i][j];
}


/*----------------- 複合代入演算子 ----------------- */
/*-------------------- 複合加算 -------------------- */
Mat3x3& Mat3x3::operator+= (const Mat3x3 &mat){
for(int i=0; i<MAT_SIZE; ++i){
  for(int j=0; j<MAT_SIZE; ++j){
    dat[i][j] = dat[i][j] + mat.dat[i][j];
  }
 }
 return *this;
}

/*-------------------- 複合減算 -------------------- */
Mat3x3& Mat3x3::operator-= (const Mat3x3 &mat){
for(int i=0; i<MAT_SIZE; ++i){
  for(int j=0; j<MAT_SIZE; ++j){
    dat[i][j] = dat[i][j] - mat.dat[i][j];
  }
 }
 return *this;
}

/*-------------------- 複合乗算 -------------------- */
Mat3x3& Mat3x3::operator*= (const Mat3x3 &mat){
  Mat3x3 c = *this;
for(int i=0; i<MAT_SIZE; ++i){
  for(int j=0; j<MAT_SIZE; ++j){
    dat[i][j] = 0.0;
    for (int k=0; k<MAT_SIZE; ++k) {
      dat[i][j] += c.dat[i][k] * mat.dat[k][j];
    }
  }
 }
 return *this;
}


/*------------------- 単項マイナス ------------------- */
// B = -A
Mat3x3 Mat3x3::operator- () const{
  Mat3x3 Nega;
  for(int i=0; i<MAT_SIZE; ++i){
    for(int j=0; j<MAT_SIZE; ++j){
      if(dat[i][j] != 0){
        Nega.dat[i][j] = -dat[i][j];
      }
    }
  }
  return Nega.dat;
}

/*------------- (i行、j列)要素にアクセス --------------*/
// double aij = A(i, j)















/*-------------------- 算術演算子 --------------------- */
/*-------------------- 行列加算(+) -------------------- */
Mat3x3 operator+ (const Mat3x3& matA, const Mat3x3& matB){
  return Mat3x3(matA) += matB;
}
/*-------------------- 行列減算(-) -------------------- */
Mat3x3 operator- (const Mat3x3& matA, const Mat3x3& matB){
  return Mat3x3(matA) -= matB;
}
/*-------------------- 行列乗算(x) -------------------- */
Mat3x3 operator* (const Mat3x3& matA, const Mat3x3& matB){
  return Mat3x3(matA) *= matB;
}



/*------------------- 等価比較演算子 --------------------*/
bool operator== (const Mat3x3& matA, const Mat3x3& matB) {
  for(int i=0; i< MAT_SIZE; ++i){
    for(int j=0; j<MAT_SIZE; ++j){

      if( matA(i, j) != matB(i, j) ) return false;
    }
  }
  return true;
}


/*
// ポインタやイテレータの場合 ...(*1)
Diff operator-(const Mat3x3& matA, const Mat3x3& matB) ;
// ポインタやイテレータの場合 ...(*2)
Mat3x3 operator-(const Mat3x3& t, Diff diff) { return t -= diff; }
*/
