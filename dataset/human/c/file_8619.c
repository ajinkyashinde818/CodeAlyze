#include <stdio.h>
int main(void){
  int n,i,a[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int j,k=0;
  for(i=0;i<=n;i++){
    j=a[k];
    if(j==2) {printf("%d\n",i + 1);return 0;}
    k=j-1;
  }
  printf("-1\n");
  return 0;
}
