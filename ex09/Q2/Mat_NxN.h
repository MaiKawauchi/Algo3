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
  Mat_NxN(){
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        dat[i][j] = 0.0;
        if(i == j) dat[i][j] = 1.0;
      }
    }
  }

   // double NxN constructor
  Mat_NxN(const T coefficients[N][N]){
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        dat[i][j] = coefficients[i][j];
      }
    }
  }

  // destructor
  ~Mat_NxN(){}

  /*
    ------------------- 代入演算子 -------------------
    Mat_NxN& operator= (const Mat_NxN& mat) &{
    for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
    dat[i][j] = mat.dat[i][j];
    }
    }
    return *this;
    }
    ----------------- move代入演算子 -----------------
    Mat_NxN& operator= (Mat_NxN&& mat) & noexcept{
    for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
    dat[i][j] = std::move(mat.dat[i][j]);
    }
    }
    return *this;
    }
  */

  T& operator() (int i, int j) { return dat[i][j]; }      // a(0, 0) == 1
  T operator() (int i, int j) const { return dat[i][j]; } // a(0, 0) == 1

  /*-------------------- 複合演算子 -------------------- */
  /*-------------------- 複合加算 -------------------- */
  Mat_NxN& operator+= (const Mat_NxN& mat){
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        dat[i][j] = dat[i][j] + mat.dat[i][j];
      }
    }
    return *this;
  }
  /*-------------------- 複合減算 -------------------- */
  Mat_NxN& operator-= (const Mat_NxN& mat){
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        dat[i][j] = dat[i][j] - mat.dat[i][j];
      }
    }
    return *this;
  }
  /*-------------------- 複合乗算 -------------------- */
  Mat_NxN& operator*= (const Mat_NxN& mat){
    Mat_NxN c = *this;
    int DAT[N][N];
    for(int i=0; i<N; ++i){
      for(int j=0; j<N; ++j){
        DAT[i][j] = 0.0;
        for (int k=0; k<N; ++k) {
          DAT[i][j] += c.dat[i][k] * mat.dat[k][j];
        }
        dat[i][j] = DAT[i][j];
      }
    }
    return *this;
  }

  // 行列の定数倍(Mat_NxN型の引数をとらない)
  Mat_NxN& operator*= (T scale){}


  /*------------------- 単項マイナス ------------------- */
  // B = -A
  Mat_NxN operator- () const{
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

  /*------------- (i行、j列)要素にアクセス --------------*/
private:
  T dat[N][N];
};




/*------------------ グローバル関数 -------------------*/
/*-------------------- 単項演算子 -------------------- */
/*-------------------- 行列加算(+) -------------------- */
template<typename T, int N>
Mat_NxN<T, N> operator+ (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB){
  return Mat_NxN<T, N>(matA) += matB;
}
/*-------------------- 行列減算(-) -------------------- */
template<typename T, int N>
Mat_NxN<T, N> operator- (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB){
  return Mat_NxN<T, N>(matA) -= matB;
}
/*-------------------- 行列乗算(x) -------------------- */
template<typename T, int N>
Mat_NxN<T, N> operator* (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB){
  return Mat_NxN<T, N>(matA) *= matB;
}



/*---------------- ストリーム挿入演算子 ----------------*/
// C++ストリームにMat_NxNオブジェクトを挿入

template<class Char, class Traits, typename T, int N>
std::basic_ostream<Char, Traits>& operator<<
(std::basic_ostream<char, Traits>& os, const Mat_NxN<T, N>& mat);

template<class Char, class Traits, typename T, int N>
std::basic_istream<Char, Traits>& operator>>
(std::basic_istream<char, Traits>& is, const Mat_NxN<T, N>& mat);

/*-------------------- 等価比較演算子 ------------------- */
// if(A == B)
template<typename T, int N>
bool operator== (const Mat_NxN<T, N>& matA, const Mat_NxN<T, N>& matB){
  for(int i=0; i< N; ++i){
    for(int j=0; j<N; ++j){
      if( matA(i, j) != matB(i, j) ) return false;
    }
  }
  return true;
}


#endif
