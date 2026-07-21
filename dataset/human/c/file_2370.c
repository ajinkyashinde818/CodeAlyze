#include<stdio.h>

int main(void){
  char s[4];
  int i;
  int a_count=0,b_count=0,c_count=0;
  scanf("%s",s);
  for(i=0;i<4;i++){
    if('a'==s[i]) a_count++;
  }
  for(i=0;i<4;i++){
    if('b'==s[i]) b_count++;
  }
  for(i=0;i<4;i++){
    if('c'==s[i]) c_count++;
  }
  if(a_count==1 && b_count==1 && c_count==1) printf("Yes");
  else printf("No");
  
  return 0;
}
