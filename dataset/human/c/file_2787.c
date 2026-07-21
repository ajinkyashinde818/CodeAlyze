#include<stdio.h>
int main(void){
  int K,S;
  int x,y,z,count;
  scanf("%d %d",&K,&S);
  for(x=0;x<=K;x++){
    for(y=0;y<=K;y++){
      if(0<=(S-x-y)&&(S-x-y)<=K) count++;
    }   
  }
  printf("%d\n",count);
  return 0;
}
