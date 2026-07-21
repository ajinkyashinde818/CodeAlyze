#include<stdio.h>
#include<stdlib.h>

int main(){
  int min,max,*R,i,n;

  scanf("%d",&n);
  R=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&R[i]);

  max=R[1]-R[0];
  min=R[0];
  for(i=1;i<n;i++){
    max=(max>R[i]-min)?max:R[i]-min;
    min=(min<R[i])?min:R[i];
  }
  printf("%d\n",max);

  return 0;
}
