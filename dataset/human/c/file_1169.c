#include<stdio.h>
#include<string.h>
int up(const void *a,const void *b){
  return *(char *)a-*(char*)b;
}
int down(const void *a,const void *b){
  return *(char *)b-*(char*)a;
}
int main(){
  char s[110],t[110];
  scanf("%s%s",s,t);
  qsort(s,strlen(s),sizeof(char),up);
  qsort(t,strlen(t),sizeof(char),down);
  if(strcmp(s,t)<0)
    puts("Yes");
  else
    puts("No");
  return 0;
}
