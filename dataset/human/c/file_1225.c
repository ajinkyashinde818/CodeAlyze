#include<stdio.h>
#include<string.h>
int main(){
  char s[101],t[101];
  scanf("%s %s",&s,&t);
  int a[strlen(s)],b[strlen(t)];
  for(int i = 0;i < strlen(s);i++){
    a[i] = s[i];
  }
  for(int i = 0;i < strlen(t);i++){
    b[i] = t[i];
  }
  for(int i = 0;i < strlen(s) - 1;i++){
    for(int j = 0;j < strlen(s) - 1;j++){
      if(a[j] > a[j + 1]){
        int t = a[j + 1];
        a[j + 1] = a[j];
        a[j] = t;
      }
    }
  }
  for(int i = 0;i < strlen(t) - 1;i++){
    for(int j = 0;j < strlen(t) - 1;j++){
      if(b[j] < b[j + 1]){
        int t = b[j + 1];
        b[j + 1] = b[j];
        b[j] = t;
      }
    }
  }
  int i = 0;
  while(a[i] == b[i] && i < strlen(s) && i < strlen(t)){
    i++;
  }if(i == strlen(t)){
    printf("No\n");
  }else if(i == strlen(s)){
    printf("Yes\n");
  }else if(a[i] < b[i]){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}
