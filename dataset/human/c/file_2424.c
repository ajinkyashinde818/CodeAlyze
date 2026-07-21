#include<stdio.h>

int main(){
  char s[4];
  int i,abc[3] = {0,0,0};
  scanf("%s",s);
  
  for(i = 0;i < 3;i++){
    if(s[i] == 'a')
      abc[0] = 1;
    if(s[i] == 'b')
      abc[1] = 1;
    if(s[i] == 'c')
      abc[2] = 1;
  }
  if(abc[0] == 1 && abc[1] == 1 && abc[2] == 1)
    puts("Yes");
  else 
    puts("No");
  
  return 0;
}
