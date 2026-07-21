#include <stdio.h>

int main(){
  int k,s,x,y,z,result=0;
  
  scanf("%d %d",&k,&s);
  
  for(x=0;x<=k;x++){
    for(y=0;y<=k;y++){
      if(0<=s-(x+y) && s-(x+y)<=k){
        result++;
      }
    }
  }
  
  printf("%d",result);
}
