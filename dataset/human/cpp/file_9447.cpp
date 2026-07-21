#include <iostream>
#include <string>
#include <vector>

bool equiv(const std::vector<std::string>& A,
           const std::vector<std::string>& B,
           size_t iu, size_t ju) {

  size_t M = B.size();
  for (size_t i = 0; i < M; ++i)
    for (size_t j = 0; j < M; ++j)
      if (A[i+iu-M][j+ju-M] != B[i][j]) return false;
  return true;
}

int main() {
  size_t N, M;
  std::cin >> N >> M;

  std::vector<std::string> A(N), B(M);
  for (auto& a: A) std::cin >> a;
  for (auto& b: B) std::cin >> b;

  for (size_t i = M; i <= N; ++i)
    for (size_t j = M; j <= N; ++j)
      if (equiv(A, B, i, j)) {
        std::cout << "Yes\n";
        return 0;
      }

  std::cout << "No\n";
}
