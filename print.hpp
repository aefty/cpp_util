#ifndef __PRINT_H__
#define __PRINT_H__

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <iomanip>      // std::setprecision
#include <cstdlib>

#include <armadillo>

namespace util_print {

bool mute = false;


inline void var(arma::Mat<double>&A, std::string varName = "") {

  std::cout << varName << ": ";

  for (int i = 0; i < A.n_rows; ++i) {
    for (int j = 0; j < A.n_cols; ++j) {
      std::cout << A(i, j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

inline void var(arma::Col<double>&v, std::string varName = "") {

  std::cout << varName << ": ";
  for (int j = 0; j < v.n_elem; ++j) {
    std::cout << v(j) << " ";
  }
  std::cout << std::endl << std::endl;
}

inline void var(arma::Row<double>&v, std::string varName = "") {

  std::cout << varName << ": ";

  for (int j = 0; j < v.n_elem; ++j) {
    std::cout << v(j) << " ";
  }
  std::cout << std::endl;
}

// Constant
inline void var(double A, std::string varName = "") {
  if (mute)return;

  std::cout << varName << ": " << A << std::endl;
}

inline void var(int A, std::string varName = "") {
  if (mute)return;

  std::cout << varName << ": " << A << std::endl;
}

// 2D Vector
inline void var(std::vector<std::vector<int>>& A, std::string varName = "") {
  if (mute)return;

  std::cout << varName << ":" << std::endl;
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A[i].size(); ++j) {
      std::cout <<  A[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// 1D Vector
inline void var(std::vector<int>& A, std::string varName = "") {
  if (mute)return;

  std::cout << varName << ":[ ";
  for (int i = 0; i < A.size() - 1; ++i) {
    std::cout <<  A[i] << ",";
  }
  std::cout << A[A.size() - 1] << " ]" << std::endl;
}

inline void var(std::vector<double>& A, std::string varName = "") {
  if (mute)return;

  std::cout << varName << ":[ ";
  for (int i = 0; i < A.size() - 1; ++i) {
    std::cout <<  A[i] << ",";
  }
  std::cout << A[A.size() - 1] << " ]" << std::endl;
}

inline void var(const double* A, int size, std::string varName = "") {
  if (mute)return;

  std::cout << varName << ":[ ";
  for (int i = 0; i < size - 1; ++i) {
    std::cout <<  A[i] << ",";
  }
  std::cout << A[size - 1] << " ]" << std::endl;
}

inline void var(const int* A, int size, std::string varName = "") {
  if (mute)return;

  std::cout << varName << ":[ ";
  for (int i = 0; i < size - 1; ++i) {
    std::cout <<  A[i] << ",";
  }
  std::cout << A[size - 1] << " ]" << std::endl;
}

// Print seperation Line
inline void line(std::string str, int n = 50) {
  if (mute)return;

  for (int i = 0; i < n; ++i) {
    std::cout << str;
  }
  std::cout << std::endl;
}

}
#endif