#include<stdio.h>
int main(){
  char s[3];
  int i;
  int flag1=0;
  int flag2=0;
  int flag3=0;
  scanf("%s",s);
  
  for(i=0;i<3;i++){
    if(s[i]=='a')
      flag1++;
    if(s[i]=='b')
      flag2++;
    if(s[i]=='c')
      flag3++;
  }
  
  if(flag1==1&&flag2==1&&flag3==1)
    printf("Yes");
  else
    printf("No");
  return 0;
}
