#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int N; ll A[100001], cnt, sum, minA = 1e10;
int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%ld", &A[i]);
    if(A[i] < 0) A[i] *= -1, ++cnt;
    minA = min(minA, A[i]);
    sum += A[i];
  }
  printf("%ld\n", cnt%2==0?sum:sum-minA*2);
}
