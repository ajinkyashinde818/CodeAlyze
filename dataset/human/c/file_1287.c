/*
AizuOnline A0082
Title
13/3/19 WA
*/
#include <stdio.h>
#define min(x,y) (((x)<(y))?(x):(y))
//Global data section
int kyaku[8];
int merry[8]={1,4,1,4,1,2,1,2};
int order[8]={5,1,6,2,8,4,7,3};
char buf[40];
//
main()
{
  int sum;
  int maxi,maxsum;
  int i,j;

  while(scanf("%d %d %d %d %d %d %d %d",
	      &kyaku[0],&kyaku[1],&kyaku[2],&kyaku[3],
	      &kyaku[4],&kyaku[5],&kyaku[6],&kyaku[7])==8)
    {
      maxsum=-1;
      maxi  =-1;
      for(i=0;i<8;i++)
	{
	  sum = 0;
	  for(j=0;j<8;j++)
	    {
	      sum += min(kyaku[j],merry[(i+j)%8]);
	    }
	  if(sum > maxsum ||( sum==maxsum && order[i]>order[maxi]))
	    {
	      maxi=i;
	      maxsum=sum;
	    }
	  //printf("%d sum %d\n",i,sum);
	}
      for(i=0;i<8;i++)
	{
	  printf("%d",merry[(i+maxi) % 8]);
	  if(i<7)
	    printf(" ");
	}
      printf("\n");
    }
return(0);
}
