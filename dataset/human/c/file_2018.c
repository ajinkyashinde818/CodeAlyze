#include<stdio.h>

int main(void)
{
int ck_a,ck_b,ck_c,count_max=0;

scanf("%d",&ck_a);
scanf("%d",&ck_b);
scanf("%d",&ck_c);
if(ck_c<=ck_a+ck_b-1)
{
  count_max = ck_b + ck_c;
}
else
{
  while(1)
  {
  if(ck_c!=0)
  {
    ck_c -= 1;
    count_max += 1;
  }
  
    if(ck_a!=0)
    {
      ck_a -= 1;
    }
    else if(ck_b!=0)
    {
      ck_b -= 1;
      count_max += 1;
    }
    else
    {
      break;
    }
  }
}


printf("%d",count_max);

  return 0;
}
