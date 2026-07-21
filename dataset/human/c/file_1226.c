#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b){
  return *(char*)a - *(char*)b;
}

int revcompare(const void *a,const void *b){
  return *(char*)b - *(char*)a;
}
int main(){
  char s[100] = {};
  char t[100] = {};
  int scnt = 0;
  int tcnt = 0;
  int i = 0;
  int j = 0;
  int flag = 0;
  
  scanf(" %s",s);
  scanf(" %s",t);
  for(i=0;i<100;i++){
    if(s[i]!='\0'){
      scnt++;
    }else{
      break;
    }
  }
  
  for(i=0;i<100;i++){
    if(t[i]!='\0'){
      tcnt++;
    }else{
      break;
    }
  }
  
  qsort(s,scnt,sizeof(char),compare);
  qsort(t,tcnt,sizeof(char),revcompare);

  flag = 0;
  if(scnt < tcnt){
    for(i=0;i<scnt;i++){
      if(s[i] > t[i]){
        flag  = -1;
        break;
      }else if(s[i] < t[i]){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      flag = 1;
    }
  }else{
    for(i=0;i<tcnt;i++){
      if(s[i] > t[i]){
        flag  = -1;
        break;
      }else if(s[i] < t[i]){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      flag = -1;
    }
  }
  if(flag == 1){
    printf("Yes");
  }else{
    printf("No");
  }
  return 0;
}
