#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp1(const void *a,const void *b){
  return *(char *)a-*(char *)b;
}
int cmp2(const void *a,const void *b){
  return *(char *)b-*(char *)a;
}

int main(){
  char s[101];
  char t[101];
  scanf("%s",s);
  scanf("%s",t);

  qsort(s,strlen(s),sizeof(char),cmp1);
  qsort(t,strlen(t),sizeof(char),cmp2);

  if(strcmp(s,t)<0){
    printf("Yes");
  }else{
    printf("No");
  }
}
