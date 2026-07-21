#include <stdio.h>

int main(){
  int K,S;
  scanf("%d %d",&K,&S);
  
  int i,j;
  int x,y,z;
  int sum,count = 0;
  
  for(j=0;j<=K;j++){
    for(i=0;i<=K;i++){
      x = i;
      y = j;
      z = S - x - y;
      
      if(z>=0 && z<=K) count++;
    }
  }
  
  printf("%d\n",count);
}
