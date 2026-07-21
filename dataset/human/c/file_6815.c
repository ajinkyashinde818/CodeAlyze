#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*3*n);
  int i;
  for(i=0;i<3*n;i++) scanf("%d",a+i);
  qsort(a,3*n,sizeof(int),cmp);
  int64 sum=0;
  for(i=3*n-2;i>=n;i-=2) sum+=a[i];
  printf("%lld\n",sum);
}

int main(void){
  run();
  return 0;
}
