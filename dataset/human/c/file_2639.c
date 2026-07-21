#include<stdio.h>
int main(){
  int a=0;
  char s[3];
  scanf("%s",s);
  for(int i = 0;i<3;i++){
    if(s[i] == 'a')
      a += 1;
    if(s[i] == 'b')
      a += 2;
    if(s[i] == 'c')
      a += 3;
  }
  if(a == 6)
    printf("Yes");
  else
    printf("No");
  return 0;
}
