#include <bits/stdc++.h>
#include <cstdint>
#include <sys/time.h>

typedef std::int_fast32_t  s32;
typedef std::uint_fast32_t u32;
typedef std::int_fast64_t  s64;
typedef std::uint_fast64_t u64;

const unsigned long mod = 1000000007;
const double EPS = 0.00000001;
const int INF = (1 << 29);

typedef std::pair<int, int> P;

template<typename T>
void print_array(T *A_, s32 size) {
  //printf("%d\n", size);
  if( size != 0 ) {
    for(int i = 0; i < size - 1; ++i) {
      printf("%d ", A_[i]);
    }
    printf("%d\n", A_[size - 1]);
  }
}

int main() {

  long N, M;
  std::cin >> N >> M;

  int ans[128];

  for(int i = 0; i < N / 2 + 1; ++i) {
    ans[i] = 0;
  }
  for(int i = N / 2 + 1; i < N; ++i) {
    ans[i] = M;
  }

  print_array(ans, N);
  
  return 0;
}
