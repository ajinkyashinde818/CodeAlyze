#include <stdio.h>
#define MAX 200000

int main(){
  int i,j,n,max=-1000000001,min=1000000001,A;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A);
    if(A - min > max && i)
      max = A-min;
    if(min > A){
      min = A;
    }
  }
  printf("%d\n",max);
  return 0;
  
}
