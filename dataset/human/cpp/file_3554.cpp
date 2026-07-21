#include <cstdio>
using namespace std;

long sum_array(long A[], int N) {
  long sum = 0;
  for (int i=0; i<N; i++) {
    sum += A[i];
  }
  return sum;
}

int main() {
  int N;
  scanf("%d", &N);

  bool inZero = false;
  int num_minus = 0;
  long min_A = 1000000000;
  long A[N];

  for (int i=0; i<N; i++) {
    long a;
    scanf("%ld", &a);
    if (a < 0){
      num_minus++;
      a *= -1;
    }
    if (a < min_A)
      min_A = a;
    A[i] = a;
  }
  long ans;
  if (min_A == 0 || num_minus%2 == 0) {
    ans = sum_array(A, N);
  } else {
    ans = sum_array(A, N) - 2*min_A;
  }
  printf("%ld\n", ans);
}
