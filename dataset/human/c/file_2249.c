/*
AizuOnline A0092
Title
2013/01/25 WA
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
//
char a[1000][1001];
int b[1000][1001];   //runlen
int n;
void print()
{
  int i,j;

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	printf("%d",b[i][j] % 10);
      printf("\n");
    }
}
main()
{
  int i,j,maxrunlen;

  while(EOF != scanf("%d",&n) && n)
    {
      //printf("N=%d\n",n);
      for(i=0;i<n;i++)
	scanf("%s",&(a[i][0]));
      if(n==1)
	{
	  if(a[0][0]=='.')
	    printf("1\n");
	  else
	    printf("0\n");
	  goto NEXT;
	}


      for(i=0;i<n;i++)
	{
	  b[i][0] = (a[i][0]=='.')?1:0;
	  b[0][i] = (a[0][i]=='.')?1:0;
	}
      maxrunlen = 0;
      for(i=1;i<n;i++)
	for(j=1;j<n;j++)
	  if(a[i][j]=='*')
	    b[i][j] = 0;
      //else if(a[i-1][j-1]=='*')
      //      b[i][j] = 1;
	  else
	    {
	      b[i][j] = 1+min(min(b[i-1][j],b[i][j-1]),b[i-1][j-1]);
	      if(b[i][j] > maxrunlen)
		maxrunlen = b[i][j];
	    }
      //print();
      printf("%d\n",maxrunlen);
    NEXT:
      ;
    }



return(0);
}
