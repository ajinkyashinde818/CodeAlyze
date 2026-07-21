#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define rep(i,n) for(int i=0; i <(n); i++)

int compint(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}
int main(){
  char s[3];
  scanf("%s",s);
  int len=strlen(s);
  rep(i,len){
    if(s[i]=='9'){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
