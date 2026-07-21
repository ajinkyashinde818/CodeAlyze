#include <stdio.h>
 
int main(void){
  int k,n,i;
  int a[200001] = {0};
  int distance = 0;
  int near = 100000000;
  
  do {
    scanf("%d ",&k);
  }while(k < 2 || k > 1000000);
  
  do {
    scanf("%d",&n);
  }while(n < 2 || n > 200000);
  
  
  for (i=1; i<n+1; i++) {
    do {
      scanf("%d ",&a[i]);
    }while(a[i] < a[i-1]);
  }
  
  for (i=1; i<n+1; i++) {
    if (i==1)
      distance = k - (k-a[n]+a[1]);
    else
      distance = k - (a[i]-a[i-1]);
    if (near > distance)
      near = distance;
  }
  
  printf("%d",near);
  
  return 0;
}
