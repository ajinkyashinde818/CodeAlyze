#include<stdio.h>
int main(void)
{
  int num, days, mod,sum=0;
  scanf("%d%d%d",&num,&days,&mod);
  int eat[num], i,j;
  for(i=0; i<num; i++)
  {
    scanf("%d",&eat[i]);
  }
  for(i=0;i<num;i++)
  {
    j=1;
    while(j<=days)
    {
      if(j%eat[i]==1 || eat[i]==1) sum++;
      j++;
    }
  }
  sum=sum+mod;
  printf("%d",sum);
  return 0;
}
