/*
AizuOnline A1011
Title
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section

//
int N;

int expt3(int n)
{
  if(n==0)
    return(1);
  else
    return(3 * expt3(n-1));
}
int calc_carbon(int n)
{
  int i,ret;

  ret=0;
  for(i=0;i<n;i++)
    ret += expt3(i);
  //printf("CC1:%d %d\n",n,ret);
  return(ret);
}
calcc(int n)
{
  int i,ret;



  if(n==1)
    return(1);
  if(n==2)
    return(2);


  if(n % 2)
    {
      ret = 2*calc_carbon((n-1)/2);
    }
  else
    ret=0;
  for(i=0;i<(n-(n % 2))/2;i++)
    ret += 4*calc_carbon(i);
    
  return(ret+n);
}
main()
{
  int ret;



  while(EOF != scanf("%d",&N))
    {
      ret=calcc(N);
      printf("%d\n",ret);
    }
return(0);
}
