#include <stdio.h>
#define MAX 200000

int main(){
  int n,i,R[MAX],max,min;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  max=-2000000000;
  min=R[0];

  for(i=1;i<n;i++){
    if(max<R[i]-min) max=R[i]-min;
    if(min>R[i]) min=R[i];
  }

  printf("%d\n",max);

  return 0;
}
