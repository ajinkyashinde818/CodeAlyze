#include <stdio.h>
int main(void){
  int n,i;
  scanf("%d",&n);
  int a[n];
  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  int cnt = 0;
  int v[n];
  v[0] = a[0];
  for(i = 1; i < n; i++){
    v[i] = a[v[i-1]-1];
  }
  for(i = 0; i < n; i++){
    cnt++;
    if(v[i] == 2){
       printf("%d",i+1); break;
    }
  }
  if(cnt == n) printf("-1");
  return 0;
}
