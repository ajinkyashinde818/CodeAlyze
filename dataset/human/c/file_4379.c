#include<stdio.h>
#include<stdlib.h>
int main(void){
  int a,b,c=0,n,i;
  char s[1005];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    if(a==b){
     c++;
      if(c>=3){
       printf("Yes");
        return 0;
      }
    }else{
     c=0; 
    }
  }
  
  printf("No");
  return 0;
}
