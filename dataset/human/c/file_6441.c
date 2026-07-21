#include<stdio.h>
#define N 200000
int main(){
  int i,j,a,min,max,R[N];
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&R[i]);
  } 
  max=R[1]-R[0];
  min=R[0];
 
  for(j=1;j<a;j++){
   max=(max>R[j]-min)?max:R[j]-min; 
   min=(min<R[j])?min:R[j];
  }
  printf("%d\n",max);
  return 0;
}
