#include <stdio.h>

int main(){
  
  int a, b, c;
  int count = 0;
  //int flag = 1;
  
  scanf("%d %d %d",&a,&b,&c);
  
  
  if(c > a){
    count = a;
    c = c - a;
    if(c > b){
      count = count + 2*b + 1;
    }
    else{
      count = count + b + c;
    }
    
  } 
  else{
    count = c + b;
   
    }
  
  printf("%d",count);
  
  
  

  return 0;
}
