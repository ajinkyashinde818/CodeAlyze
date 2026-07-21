#include<stdio.h>
int main()
{
  char s[4];
  int x=0,y=0,z=0;
  int i;
  scanf("%s", s);
  for(i=0;i<3;i++){
    if(s[i]=='a')
      x=1;
    if(s[i]=='b')
      y=1;
    if(s[i]=='c')
      z=1;
  }
  if(x==1&&y==1&&z==1)
  printf("Yes");
  else
    printf("No");
    return 0;
}
