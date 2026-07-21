/*
  AOJ 2205
  Title:Lottery Checker
  @kankichi573
*/
#include <stdio.h>

int n,m;
char tousen[1000][9];
int  shoukin[1000];
char mykuji[9];

my_match(char c1,char c2)
{
  return((c1==c2)||(c1=='*'));
}

mystrncmp(char s1[],char s2[],int n)
{
  int i;
  for(i=0;i<n;i++)
    if(!my_match(s1[i],s2[i]))
      return(0);
  return(-1);
}
solve(char kuji[])
{
  int i,sum;
  sum=0;
  for(i=0;i<n;i++)
    {
      //printf("%s %s",&tousen[i][0],kuji);
      if(mystrncmp(&tousen[i][0],kuji,8))
	sum += shoukin[i];
    }
  return(sum);
}
main()
{
  int i,sum;

  while(scanf("%d %d",&n,&m) && (n||m))
    {
      for(i=0;i<n;i++)
	scanf("%s %d",&tousen[i][0],&shoukin[i]);
      sum=0;
      for(i=0;i<m;i++)
	{
	  scanf("%s",mykuji);
	  //printf("%s\n",mykuji);
	  sum += solve(mykuji);
	}
      printf("%d\n",sum);
    }
  return(0);
}
