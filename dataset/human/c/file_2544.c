#include<stdio.h>

int main(void)
{
  char S[4];
  int flag[3]={0,0,0};

  scanf("%s",S);

  for (int i = 0; i < 3; i++)
  {
    if(S[i]=='a')
      flag[0]=1;
      else if(S[i]=='b')
        flag[1]=1;
        else if(S[i]=='c')
          flag[2]=1;
  }

if(flag[0]==1&&flag[1]==1&&flag[2]==1)
  printf("Yes\n");
else
  printf("No\n");

  return 0;
}
