#include<stdio.h>

int main()
{
  char string[3];
  scanf("%s",string);
  int a=0; int b=0; int c=0;
  for(int i=0;i<3;++i){
    if(string[i]=='a')  a=1;
    else if(string[i]=='b')  b=1;
    else if(string[i]=='c')  c=1;
  }
  if(a==1 && b==1 && c==1)  printf("Yes\n");
  else  printf("No\n");
  return 0;
}
