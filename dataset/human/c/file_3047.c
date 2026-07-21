#include <stdio.h>
 
int main(void){
  
  int k,n;
  int a[200000];
  int i,d=0;
  
  scanf("%d %d", &k, &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  
  for(i = 0; i < (n-1); i++){
    if((a[i+1]-a[i]) > d){
      d = (a[i+1]-a[i]);
    }
  }
  if((k-a[n-1]+a[0]) > d){
    d = (k-a[n-1]+a[0]);
  }
  printf("%d", (k-d));
  
  return 0;
}
