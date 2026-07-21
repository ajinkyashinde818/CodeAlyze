/*
  AOJ 0318
  Programing contest
  @kankichi573
 */
#include <stdio.h>
#include <string.h>

int n;
char table[101];

int main()
{
  int x,i,j,p;

  memset(table,0,sizeof(table));
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&p);
      for(j=1;j<=p;j++)
	table[j]++;
    }
    
  #ifdef DEBUG  
  for(i=1;i<=n;i++)
  	printf("%d ",table[i]);
  printf("\n");
  #endif

  for(i=1;i<=n;i++)
    if(i>table[i])
      {
	printf("%d\n",i-1);
	return(0);
      }
  printf("%d\n",n);
  return(0);
  }
