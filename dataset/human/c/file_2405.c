#include <stdio.h>

int main(void)
{
  int flagA=0,flagB=0,flagC=0,i;
  char abc[4];
  
  scanf("%s",abc);
  
  for(i=0;i<3;i++)
  {
    if(abc[i]=='a')
      flagA += 1;
  }
  
  for(i=0;i<3;i++)
  {
    if(abc[i]=='b')
      flagB += 1;
  }
  
  for(i=0;i<3;i++)
  {
    if(abc[i]=='c')
      flagC += 1;
  }
  
  if(flagA==1&&flagB==1&&flagC==1)
  printf("Yes");
  else
  printf("No");
  
	return 0;
}
