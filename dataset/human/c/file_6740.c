/*
AizuOnline A0545
Title Party
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
int m,n;
int a[10000];
int b[10000];
int f[501];
int cnt;
//
main()
{
  int i;

  while(1)
    {
      scanf("%d",&n);
      scanf("%d",&m);

      if(m == 0 && n == 0)
	break;
      for(i=0;i<m;i++)
	scanf("%d %d",&(a[i]),&(b[i]));
      for(i=1;i<=n;i++)
	f[i]=0;
      for(i=0;i<m;i++)
	{
	  if(a[i] == 1)
	    f[b[i]] = 1;
	  if(b[i] == 1)
	    f[a[i]] = 1;
	}
      for(i=0;i<m;i++)
	{
	  if(f[a[i]] == 1 && f[b[i]]==0)
	    f[b[i]] = 2;
	  if(f[b[i]] == 1 && f[a[i]]==0)
	f[a[i]] = 2;
	}

      cnt = 0;
      for(i=2;i<=n;i++)
	cnt += ((f[i])?1:0);

      printf("%d\n",cnt);
    }

return(0);
}
