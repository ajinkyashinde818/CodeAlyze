#include <iostream>
#include <string>

int main() {
  int N, M;
  std::cin >> N >> M;
  std::string A[N], B[M];
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    std::cin >> B[i];
  }

  bool exist = false;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if ( j + M - 1 >= N || i + M - 1 >= N ) continue;
      bool match = true;
      for (int ii = 0; ii < M; ++ii) {
        for (int jj = 0; jj < M; ++jj) {
          if ( A[i + ii][j + jj] != B[ii][jj] ) match = false;
        }
      }
      if ( match ) exist = true;
    }
  }
  if ( exist ) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
