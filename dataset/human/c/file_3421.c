#include<stdio.h>
#include<string.h>
int main(void){
  char s[100000];
  int i = 0;
 
  if(scanf("%s",s));
 
  //printf("iA= %d",i);
  while(1){
    if(strncmp("dream",&s[i],5)==0){
      i += 5;
      //printf("iB= %d",i);
      if(strncmp("er",&s[i],2)==0 && strncmp("era",&s[i],3)!=0){
        i += 2;
         //printf("iBC= %d",i);
      }
    }
    else if(strncmp("erase",&s[i],5)==0){
      i += 5;
       //printf("iC= %d",i);
      if(strncmp("r",&s[i],1)==0 /*&& strncmp("ra",&s[i],2)!=0*/){
        i += 1;
         //printf("iD= %d",i);   
      }
    } 
    else if(s[i] == '\0'){
      printf("YES");      
      break;
    }
    else{
      printf("NO");
      break;
    }
  }
  
  //if(noFrag ==0)
  //  printf("YES");
  
  
  return 0;
}
