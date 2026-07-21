#include<stdio.h>
#include<string.h>
#define N 100
int main(){
  int tmp;
  char s[N] = {'\0'};
  char t[N] = {'\0'};
  scanf("%s", s);
  scanf("%s", t);
  int i = 0, j = 0;

  for(i = 0; i < strlen(s); i++){
    for(j = i + 1; j < strlen(s); j++){
      if(s[i] > s[j]){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i = 0;
      }
    }
  }
  for(i = 0; i < strlen(t); i++){
    for(j = i + 1; j < strlen(t); j++){
      if(t[i] < t[j]){
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
        i = 0;
      }
    }
  }
  for(i = 0; s[i] != '\0' && t[i] != '\0'; i++){
    if(s[i] != t[i]){
      if(s[i] > t[i]){
        printf("No\n");
        return 0;
      }else{
        printf("Yes\n");
        return 0;
      }
    }
  }
  if(strlen(s) > strlen(t)){
    printf("No\n");
  }else if(strlen(s) < strlen(t)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  return 0;
}
