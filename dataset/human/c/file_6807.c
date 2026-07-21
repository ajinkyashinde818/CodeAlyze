#include<stdio.h>
#include<stdlib.h>

int down(const void *a,const void *b){
  return *(int *)b - *(int *)a;
}

int main(void){
  
  int n;
  scanf("%d",&n);

  int m = 3*n;
  int a[m];
  for(int i = 0;i < m;i ++){
    scanf("%d",&a[i]);
  }

  qsort(a,m,sizeof(int),down);
  long long ans = 0;
  for(int i = 1;i < 2*n;i += 2){
    ans += a[i];
  }

  printf("%lld\n",ans);

  return 0;
}
