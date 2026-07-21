#include <stdio.h>

int main(){
  int N,D,X,sche;
  int count=0,check=1;

  scanf("%d%d%d",&N,&D,&X);

  for(int i=0;i<N;i++){
   scanf("%d",&sche);
   check=1;
   while(1){
     check+=sche;
     if(check<=D)count++;
     else break;
   }
 }
 printf("%d",count+X+N);
 return 0;
}
