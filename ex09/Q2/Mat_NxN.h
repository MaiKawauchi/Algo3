#ifndef MAT_NxN_H
#define MAT_NxN_H

#include <iostream>
#include <cstdlib>

using namespace std;

/*---------------------------------------------------------------------*/
// T : マトリックス内の要素のタイプ
// N : 次元
/*---------------------------------------------------------------------*/
template<typename T, int N>
class Mat_NxN{
public:
  // defoult constructor
  Mat_NxN();

  // copy constructor(one argument)
  Mat_NxN(const Mat_NxN& mat);

   // double 3x3 constructor
  Mat_NxN(const double coefficients[N][N]);

  // destructor
  ~Mat_NxN();

  Mat_NxN& operator= (const Mat_NxN& mat) &;   // 代入演算子
  Mat_NxN& operator= (Mat_NxN&&) & noexcept;   // move代入演算子

  double& operator() (int i, int j);      // a(0, 0) == 1
  double operator() (int i, int j) const; // a(0, 0) == 1


  /*-------------------- 複合演算子 -------------------- */
  // B = B + A
  Mat_NxN& operator+= (const Mat_NxN& mat); // 行列の複合加算
  Mat_NxN& operator-= (const Mat_NxN& mat); // 行列の複合減算
  Mat_NxN& operator*= (const Mat_NxN& mat); // 行列の複合乗算
  Mat_NxN& operator*= (double scale); // 行列の定数倍(Mat_NxN型の引数をとらない)


  /*------------------- 単項マイナス ------------------- */
  // B = -A
  Mat_NxN operator- () const;

  /*------------- (i行、j列)要素にアクセス --------------*/
  // double aij = A(i, j)
private:
  T dat[3][3];
};




/*------------------ グローバル関数 -------------------*/
/*-------------------- 単項演算子 -------------------- */
// C = A + B
template<typename T, int N>
Mat_NxN<T, N> operator+ (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB); // 行列の加算
template<typename T, int N>
Mat_NxN<T, N> operator- (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB); // 行列の減算
template<typename T, int N>
Mat_NxN<T, N> operator* (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB); // 行列の乗算

/*---------------- ストリーム挿入演算子 ----------------*/
// C++ストリームにMat_NxNオブジェクトを挿入
/*
template<class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<
(std::basic_ostream<char, Traits>& os, const Mat_NxN&);

template<class Char, class Traits>
std::basic_istream<Char, Traits>& operator>>
(std::basic_istream<char, Traits>& is, const Mat_NxN&);
*/
/*-------------------- 等価比較演算子 ------------------- */
// if(A == B)
template<typename T, int N>
bool operator== (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB);


#endif
