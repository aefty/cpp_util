#ifndef __PRINT_H__
#define __PRINT_H__

namespace cpp_util {
  bool IGNORE_PRINT = false;

  // Constant
  void printd(double* A, string varName = "") {
    if (IGNORE_PRINT) { return; }
    cout << varName << ": " << A << endl;
  }
  void printd(int* A, string varName = "") {
    if (IGNORE_PRINT) { return; }
    cout << varName << ": " << A << endl;
  }

  // 2D Vector
  void printd(vector<vector<int>>& A, string varName = "") {
    if (IGNORE_PRINT) { return; }
    cout << varName << ":" << endl;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A[i].size(); ++j) {
        cout <<  A[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  // 1D Vector
  void printd(vector<int>& A, string varName = "") {
    if (IGNORE_PRINT) { return; }
    cout << varName << ":[ ";
    for (int i = 0; i < A.size() - 1; ++i) {
      cout <<  A[i] << ",";
    }
    cout << A[A.size() - 1] << " ]" << endl;
  }
  void printd(vector<double>& A, string varName = "") {
    if (IGNORE_PRINT) { return; }
    cout << varName << ":[ ";
    for (int i = 0; i < A.size() - 1; ++i) {
      cout <<  A[i] << ",";
    }
    cout << A[A.size() - 1] << " ]" << endl;
  }
  void printd(const double* A, int size, string varName = "") {
    if (IGNORE_PRINT) { return; }
    cout << varName << ":[ ";
    for (int i = 0; i < size - 1; ++i) {
      cout <<  A[i] << ",";
    }
    cout << A[size - 1] << " ]" << endl;
  }
  void printd(const int* A, int size, string varName = "") {
    if (IGNORE_PRINT) { return; }
    cout << varName << ":[ ";
    for (int i = 0; i < size - 1; ++i) {
      cout <<  A[i] << ",";
    }
    cout << A[size - 1] << " ]" << endl;
  }

  // Print seperation Line
  void printd() {
    if (IGNORE_PRINT) { return; }
    cout << "========================================" << endl;
  }

  // Print message
  void printd(string message) {
    if (IGNORE_PRINT) { return; }
    cout << message << endl;
  }
}
#endif