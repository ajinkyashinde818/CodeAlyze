#include<stdio.h>
#include<limits.h>

int main(void)
{
char S[2];

  int i;
  
  for(i=0;i<3;i++)
  {
scanf("%c", &S[i]);
  }
if(S[0]==S[1]||S[0]==S[2]||S[1]==S[2])
{
printf("No");
}
  else
  {
  printf("Yes");
  }
return 0;
}
