#include<stdio.h>
int main(){
  int n, d, ans, i, j;
  scanf("%d %d %d", &n, &d, &ans);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  for(j=0;j<n;j++){
    for(i=1;i<=d;i+=a[j]){
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
