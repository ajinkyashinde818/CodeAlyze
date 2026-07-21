#include<stdio.h>

int main(){
  long long int a[1000000];
  long long int res, ans=100000000000000000LL, X=0LL,x=0LL;
  int i, j, n;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%lld", &a[i]);
    X+=a[i];
  }

  for(i=0; i<n-1; i++){
    x+=a[i];
    res=X-2*x;
    if(res<0){
      res*=-1;
    }
    if(res<ans){
      ans=res;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
