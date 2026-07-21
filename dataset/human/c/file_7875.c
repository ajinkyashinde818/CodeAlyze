/*
AizuOnline A0519
Title Worst sport writer

*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
#define SHOUGENNO 100000
#define NINZUU 5000
int n,m;
int x[SHOUGENNO],y[SHOUGENNO];
int flag[NINZUU+1];
//
void show()
{
  int i;
  for(i=1;i<=n;i++)
    printf("%d:",flag[i]);
  printf("\n");
}
main()
{
  int i,cnt,cnt2,multi;

  scanf("%d ",&n);
  scanf("%d ",&m);
  for(i=0;i<m;i++)
    scanf("%d %d",&x[i],&y[i]);
  for(i=0;i<n;i++)
    flag[i]=0;

  cnt=n;multi=0; 

  while(cnt>0)
    {
      for(i=1;i<=n;i++)
	if(flag[i]>0)
	  flag[i]=0;
      //show();
      for(i=0;i<m;i++)
	if(flag[x[i]]!=-1)
	  flag[y[i]]=1;
      cnt2=0;
      for(i=1;i<=n;i++)
	{
	  if(flag[i]==0)
	    {
	      printf("%d\n",i);
	      cnt--;
	      flag[i]=-1;
	      cnt2++;
	      if(cnt2>1)
		multi=1;
	    }
	}
      //show();
    }
  printf("%d\n",multi);  
  return(0);
}
