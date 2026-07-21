#include <stdio.h>
#include <string.h>

int main(){
  char s[100001],t1[6],t2[7],t3[8];
  int i,j,len,flag=0;
  
  scanf("%s",s);
  len=strlen(s);
  i=len-1;
  while(i>=4 && flag==0){
    if(i>=4){
      strncpy(t1, &s[i-4], 5);
    } else {
      t1[0]='\0';
    }
    
    if(i>=5){
      strncpy(t2, &s[i-5], 6);
    } else {
      t2[0]='\0';
    }
    
    if(i>=6){
      strncpy(t3, &s[i-6], 7);
    } else {
      t3[0]='\0';
    }
    
    if(strcmp(t1,"dream")==0 || strcmp(t1,"erase")==0){
      i-=5;
    } else if(strcmp(t2,"eraser")==0){
      i-=6;
    } else if(strcmp(t3,"dreamer")==0){
      i-=7;
    } else {
      flag=1;
    }
  }
  
  if(flag==1){
    printf("NO");
  } else {
    printf("YES");
  }
}
