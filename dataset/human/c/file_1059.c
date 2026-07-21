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

int compare_long(const void *a, const void *b) {
  return *(long*)a - *(long*)b;
}

int main() {
  long N, C;
  long i, j;
  long tans = 0;
  char buf[201];
  long len;
  
  ss(buf);
  len = strlen(buf);
  for(i=0;i<len-8;i++) {
    printf("%c", buf[i]);
  }
  printf("\n");
  
  
  return 0;
}
