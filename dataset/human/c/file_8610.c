#include <stdio.h>
int main(){
  int n, a[100000]={0};
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    a[i]--;
  }
  int cnt=1, idx=0;
  while(cnt <= n){
    if( a[idx] == 1 ){ printf("%d\n", cnt); return 0; }
    cnt++;
    idx = a[idx];
  }
  printf("-1\n");
  return 0;
}
