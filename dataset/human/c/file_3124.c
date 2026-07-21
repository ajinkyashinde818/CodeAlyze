#include <stdio.h>

int main(void){
  int k,n;
  int longn = 0;
  scanf("%d",&k);
  scanf("%d",&n);
  int a[n];
  for(int i = 0;i < n;i++){
    scanf("%d ",&a[i]);
    if((i == n - 1) && (longn < (k - a[n-1] + a[0]))){
      longn = k -a[n-1] + a[0];
    }
    else if((a[i] - a[i-1])> longn && i > 0){
      longn = a[i] - a[i-1];
    }
  }
  printf("%d\n",k - longn);
  return 0;
}
