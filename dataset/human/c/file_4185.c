#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
  
 int ans[255];
 int a,b,k,i,j;
  scanf("%d %d %d",&a,&b,&k);
  
  for(i = 1;i < 101;i++){
    if(a % i == 0 && b % i == 0){
      ans[j] = i;
      j++;
    }
  }
  
  printf("%d",ans[j - k]);
    
  
      return 0;
  
}
