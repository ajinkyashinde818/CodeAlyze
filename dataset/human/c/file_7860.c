/*
  AOJ 1016
  Title:Fibonacci Sets
  @kankichi573
*/
#include <stdio.h>

int F[1001];
int V,d;

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}


void make_fib(int d)
{
  int i;

  F[0]=1;F[1]=2;
  for(i=2;i<=d;i++)
    F[i]=(F[i-1]+F[i-2])%1001;

}
main()
{
  int i,cnt;

  while(EOF!=scanf("%d %d",&V,&d))
    {
      make_fib(V);

      qsort(F,V+1,sizeof(int),compare_int);

      //     for(i=1;i<=V;i++)
      //	printf("%d:",F[i]);

      cnt=1;
      for(i=2;i<=V;i++)
	{
	  if(F[i]-F[i-1]>=d)
	    {
	      cnt++;
	      //printf("\n");
	    }
	  //printf("%d;",F[i]);
	}
      printf("%d\n",cnt);
    }
  return(0);
}
