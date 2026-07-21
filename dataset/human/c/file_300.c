#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MOD 998244353

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int compare_int(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}


typedef long long int64;

int main(void){
  int N;
  scanf("%d",&N);
  int A[N];
  int mi=0;
  int min;
  int64 ans=0;
  for(int i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(A[i]<0) mi++;
    A[i]=fabs(A[i]);
    ans+=A[i];
  }
  qsort(A,N,sizeof(int),compare_int);
  if(mi%2) ans-=A[0]*2;
  printf("%lld",ans);

  return 0;
}
