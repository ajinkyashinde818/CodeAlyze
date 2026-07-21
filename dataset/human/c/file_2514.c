#include<stdio.h>
int main(void){
  char s[4];
  int i,j;
  int cnt=0;
  
  scanf("%s",s);
  
  for(i=0;i<4;i++){
    for(j=i+1;j<4;j++){
      if(s[i]==s[j]){
        cnt++;
      }
    }
  }
    
   if(cnt==0){
     printf("Yes\n");
   }
    else{
     printf("No\n");
    }
    return 0;
  }
