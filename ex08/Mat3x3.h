#ifndef Mat3x3_h
#define Mat3x3_h

#include <iostream>
#include <cstdlib>

using namespace std;

class Mat3x3{
public:
  // defoult constructor
  Mat3x3();

  // copy constructor(one argument)
  Mat3x3(const Mat3x3& mat);

   // double 3x3 constructor
  Mat3x3(const double coefficients[3][3]);

  // destructor
  ~Mat3x3();

  Mat3x3& operator= (const Mat3x3& mat) &;  // 代入演算子
  Mat3x3& operator= (Mat3x3&&) & noexcept;   // ムーブ代入演算子

  double& operator() (int i, int j); // a(0, 0) == 1
  double operator() (int i, int j) const; // a(0, 0) == 1


  /*-------------------- 複合演算子 -------------------- */
  // B = B + A
  Mat3x3& operator+= (const Mat3x3& mat); // 行列の複合加算
  Mat3x3& operator-= (const Mat3x3& mat); // 行列の複合減算
  Mat3x3& operator*= (const Mat3x3& mat); // 行列の複合乗算
  Mat3x3& operator*= (double scale); // 行列の定数倍(Mat3x3型の引数をとらない)


  /*------------------- 単項マイナス ------------------- */
  // B = -A
  Mat3x3 operator- () const;

  /*------------- (i行、j列)要素にアクセス --------------*/
  // double aij = A(i, j)

private:
  double dat[3][3];
};




/*------------------ グローバル関数 -------------------*/
/*-------------------- 単項演算子 -------------------- */
// C = A + B
Mat3x3 operator+ (const Mat3x3& matA, const Mat3x3& matB); // 行列の加算
Mat3x3 operator- (const Mat3x3& matA, const Mat3x3& matB); // 行列の減算
Mat3x3 operator* (const Mat3x3& matA, const Mat3x3& matB); // 行列の乗算

/*---------------- ストリーム挿入演算子 ----------------*/
// C++ストリームにMat3x3オブジェクトを挿入
template<class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<
(std::basic_ostream<char, Traits>& os, const Mat3x3&);

template<class Char, class Traits>
std::basic_istream<Char, Traits>& operator>>
(std::basic_istream<char, Traits>& is, const Mat3x3&);

/*-------------------- 等価比較演算子 ------------------- */
// if(A == B)
bool operator== (const Mat3x3& matA, const Mat3x3& matB);


#endif
