#include <stdio.h>
#define N 200000
int a[N];
int n;
int max(int a[]){
  int res = 0;
  for(int i=0;i<n;i++){
    if(res < a[i])res = a[i];
  }
  return res;
}
void solve(){
  int k,i;
  scanf("%d%d", &n,&k);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  int l=0,r=max(a);
  while(r-l>1){
    int mid = (l+r)/2;
    int tmp = 0;
    for(i=0;i<n;i++){
      tmp += (a[i]+mid-1)/mid - 1;
    }
    if(tmp <= k){
      r = mid;
    }else{
      l = mid;
    }
  }
  printf("%d\n", r);
}
int main(){
  solve();
  return 0;
}
