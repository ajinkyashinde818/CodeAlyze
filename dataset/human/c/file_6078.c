#include<stdio.h>
#define N 200000
 
int main()
{
  int FX[N],i,num,mim,max;
 
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&FX[i]);
  }
 
  max=FX[1]-FX[0];
  mim=FX[0];
 
  for(i=1;i<num;i++){
    max=(max>FX[i]-mim)? max :FX[i]-mim;
    mim=(mim<FX[i])? mim :FX[i];
  }
 
  printf("%d\n",max);
  return 0;
}
