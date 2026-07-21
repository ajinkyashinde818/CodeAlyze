#include<stdio.h>
#include<stdlib.h>

int main (void){
  int z=0;
  int y[10000];
  for(;;){
  int x;
  scanf("%d",&x);
  if(1<=x<=10000 && x!=0){
  y[z]=x;
  z++;
  }
  else{
    break;
  }
  }

  int z1,z2;
  for(z1=0;z1<z;z1++){
    z2=z1+1;
    printf("Case %d: %d\n",z2,y[z1]);
  }

  return(0);
}
