#include <stdio.h>
int main(void){
  int n,i,a[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int count=1,j,k=0;
  for(i=0;i<=n;i++){
    j=a[k];
    if(j==2) {printf("%d",count);return 0;}
    k=j-1;
    count++;
  }
  printf("-1");
  return 0;
}
