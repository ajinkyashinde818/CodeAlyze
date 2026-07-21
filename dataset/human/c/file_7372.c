#include<stdio.h>

int main(){
  int x;
  int i,j;
  int y[10000];
  for(i=0;i<10000;i++){
    scanf("%d",&x);
    if(x==0){
      break;
    }
    y[i] = x;
  }
  for(j=0;j<i;j++){
    printf("Case %d: %d\n",j+1,y[j]);
  }
  return 0;
}
