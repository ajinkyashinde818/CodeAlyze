#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
 int i,j;
  char S[4],str[10],buff,*p;
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  strcpy(S,p);
  
  for(i=0;i<2;i++){
    for(j=2;j>i;j--){
     if(S[j-1]>S[j]){
       buff=S[j-1],S[j-1]=S[j],S[j]=buff;
     }
    }
  }
  
  if(strcmp(S,"abc")==0){
   printf("Yes\n");
    return 0;
  }
  
  printf("No\n");
  
  return 0;
}
