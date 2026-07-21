#include <stdio.h>
#define MAX 100

int main(void){
  char s[MAX],t[MAX];
  int i,j,save,l,judge=0;
  scanf("%s %s",s,t);
  for(i=0;i<strlen(s);i++){
    for(j=i+1;j<strlen(s);j++){
      if(s[i] > s[j]){
        save = s[i];
        s[i] = s[j];
        s[j] = save;
      }
    }
  }
  for(i=0;i<strlen(t);i++){
    for(j=i+1;j<strlen(t);j++){
      if(t[i] < t[j]){
        save = t[i];
        t[i] = t[j];
        t[j] = save;
      }
    }
  }
  if(strlen(s) <= strlen(t)){
    l = strlen(s);
  }
  else{
    l = strlen(t);
  }
  for(i=0;i<l;i++){
    if(s[i] <t[i]){
      printf("Yes");
      judge++;
      break;
    }
    else if(s[i] >t[i]){
      printf("No");
      judge++;
      break;
    }
  }
  if(judge == 0 && strlen(s) < strlen(t)){
    printf("Yes");
  }
  else if(judge == 0){
    printf("No");
  }
  return 0;
}
