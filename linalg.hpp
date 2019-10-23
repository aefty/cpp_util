#ifndef __LINALG_H__
#define __LINALG_H__


namespace util_linalg {

inline double dot(vector<double>& A , vector<double>& B) {
  double rtrn = 0;
  for (int i = 0; i < A.size(); ++i) {
    rtrn += A[i] * B[i];
  }
  return rtrn;
}

inline double l2(vector<double>& A) {
  double rtrn = 0;
  for (int i = 0; i < A.size(); ++i) {
    rtrn += A[i] * A[i];
  }
  return pow(rtrn, 0.5);
}

inline double l2(double* A, int d) {
  double rtrn = 0;
  for (int i = 0; i < d; ++i) {
    rtrn += A[i] * A[i];
  }
  return pow(rtrn, 0.5);
}

inline void sdot(double a, vector<double>& A ,  vector<double>& rtrn) {
  for (int i = 0; i < A.size(); ++i) {
    rtrn[i] =  a * A[i];
  }
}

inline void less(vector<double>& A,  vector<double>& B) {
  for (int i = 0; i < A.size(); ++i) {
    A[i] -= B[i];
  }
}

inline void less(double* A,  vector<double>& B) {
  for (int i = 0; i < B.size(); ++i) {
    A[i] -= B[i];
  }
}

inline void less(double* A, double* B, int size) {
  for (int i = 0; i < size; ++i) {
    A[i] -= B[i];
  }
}

inline void add(double* A, vector<double>& B) {
  for (int i = 0; i < B.size(); ++i) {
    A[i] += B[i];
  }
}

inline void add(vector<double>& A, double* B) {
  for (int i = 0; i < A.size(); ++i) {
    A[i] += B[i];
  }
}

inline void add(vector<double>& A,  vector<double>& B) {
  for (int i = 0; i < A.size(); ++i) {
    A[i] += B[i];
  }
}

inline void add(vector<double>& A,  vector<double>& B, vector<double>& rtrn) {
  for (int i = 0; i < A.size(); ++i) {
    rtrn[i] = A[i]  + B[i];
  }
}

inline void add(double a, vector<double>& A,  double b, vector<double>& B, vector<double>& rtrn) {
  for (int i = 0; i < A.size(); ++i) {
    rtrn[i] = a * A[i]  + b * B[i];
  }
}
}
#endif