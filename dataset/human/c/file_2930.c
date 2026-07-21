#include<stdio.h>
int main()
{
  int k,s,srx=0;
  scanf("%d%d",&k,&s);
  for(int x=0;x<=k;x++) 
  {for(int y=0;y<=k;y++) 
  {int z=s-x-y;
  if(0<=z&&z<=k)
  srx++;}}
  printf("%d\n",srx);
  return 0;
}
