#include<stdio.h>
int main(void)
{
  int i,Case[10001],count=0;
  while(1)
  {
    scanf("%d",&Case[count]);
    if(Case[count]==0)
      break;
    count++;
  }
  for(i=0;i<count;i++)
  {
    printf("Case %d: %d\n",i+1,Case[i]);
  }
  return 0;
}
