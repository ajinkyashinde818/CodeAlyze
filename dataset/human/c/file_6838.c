#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a,const int *b){
  return *b-*a;
}
int main(){
  int n,a[334000],i;
  scanf("%d",&n);
  for(i=0;i<3*n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,3*n,4,cmp);
  long long ans;
  for(i=1;i<=n*2;i+=2){
    ans+=a[i];
  }
  printf("%lld",ans);
}
