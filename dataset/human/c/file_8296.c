#include<stdio.h>
#include<string.h>
int main(void){
  int n,k;
  scanf("%d",&n);
  char s[n + 1];
  scanf("%s %d",&s,&k);
  for(int i = 0;i < n;i++){
    if(s[i] == s[k - 1]){
      printf("%c",s[i]);
    }else{
      printf("*");
    }
  }
  return 0;
}
//scanf("%d",&);
//printf("%d\n",);
