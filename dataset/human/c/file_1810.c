#include <stdio.h>

int main(void){
  int n,i,j,x,y,z;
  scanf("%d", &n);
  int a[n+1];
  int b[51];
  int c[51];
  for(x=1;x<=n;x++){
    scanf("%d", &a[x]);
  }
  for(y=1;y<=n;y++){
    scanf("%d", &b[y]);
  }
  for(z=1;z<=n-1;z++){
    scanf("%d", &c[z]);
  }
  int sum=0;
  
  for(i=1;i<=n;i++){
    sum += b[i];
  }
  
  for(j=1;j<=n-1;j++){
    if(a[j]+1==a[j+1]){
      sum += c[a[j]];
  }
 }
  printf("%d", sum);
  return 0;
}
