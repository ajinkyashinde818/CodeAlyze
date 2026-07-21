#include <stdio.h>

int main(){
  int n,d,x,a[100];
  int count = 0;
  int i,j;
  scanf("%d %d %d",&n,&d,&x);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }

  for(i = 0;i < n;i++){
    for(j = 1;j <= d;j = j+a[i]){
      count++;
    }
  }

  printf("%d\n",count + x);
  return(0);
}
