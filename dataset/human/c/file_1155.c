#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char s[101];
  char t[101];
  char tmp;
  int i, j;
 
  scanf("%s",s);
  scanf("%s",t);
  
  for(i=0;i<(int)strlen(s)-1;i++){
    for(j=i+1;j<(int)strlen(s);j++){
      if(s[i] > s[j]){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
      }
    }
  }
  for(i=0;i<(int)strlen(t)-1;i++){
    for(j=i+1;j<(int)strlen(t);j++){
      if(t[i] < t[j]){
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
      }
    }
  }
  if(strcmp(s,t)<0)
    printf("Yes\n");
  else
    printf("No\n");
  
  return 0;
}
