#include<stdio.h>

int main(){
  int i,l,a;
  char s[16];
  scanf("%d%s%d",&l,s,&a);
  for(i=0;i<l;i++){
    if(s[i]!=s[a-1]){printf("*");}
    else{printf("%c",s[i]);}
  }
  printf("\n");
  return 0;
}
