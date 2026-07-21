#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define pd(x) printf("%lf\n", x)
#define ps(x) printf("%s\n", x)

#define INF 1000000000000000000
#define MOD 1000000007

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int main() {
  long N, K, S;
  long i, j;
  long ans = 0;
  
  sl(N); sl(K); sl(S);
  if(N == K) {
    for(i=0;i<N;i++) {
      if(i < N-1) printf("%ld ", S);
      else printf("%ld\n", S);
    }
  } else if(S == 1) {
    for(i=0;i<K;i++) {
      printf("1 ");
    }
    for(i=K;i<N;i++) {
      if(i < N-1) printf("1000000000 ");
      else printf("1000000000\n");
    }
  } else {
    for(i=0;i<K+1;i++) {
      if(i%2 == 0) printf("%ld ", S-1);
      else printf("1 ");
    }
    if(S == 1000000000) {
      for(i=K+1;i<N;i++) {
        if(i < N-1) printf("500000001 ");
        else printf("500000001\n");
      }
    } else {
      for(i=K+1;i<N;i++) {
        if(i < N-1) printf("1000000000 ");
        else printf("1000000000\n");
      }
    }
  }
  
  return 0;
}
