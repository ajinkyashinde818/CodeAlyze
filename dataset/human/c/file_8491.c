/*
  AOJ 1193
  Title:Chain Disappearance Puzzle
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

char ban[10][5];
int n;
void show()
{
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=0;j<5;j++)
	printf("%d|",ban[i][j]);
      printf("\n");
    }
  printf("----------\n");
}

void shrink()
{
  int i,j,k;
  char ban2[10][5];

  for(i=0;i<5;i++)
    {
      for(j=n-1,k=n-1;j>=0;j--)
	if(ban[j][i])
	  {
	    ban2[k][i]=ban[j][i];
	    k--;
	  }
      for(j=k;j>=0;j--)
	ban2[j][i]=0;
    }
  memcpy(ban,ban2,50);
}
int delete3()
{
  int sum,i,j,p,ret;
  char del[5];

  for(i=0,ret=0;i<n;i++)
    {
      p=0;
      memset(del,0,5);
      if(ban[i][0]>0 && ban[i][0]==ban[i][1] && ban[i][1]==ban[i][2])
	{
	  del[0]=del[1]=del[2]=1;
	  p=ban[i][0];
	}
      if(ban[i][1]>0 && ban[i][1]==ban[i][2] && ban[i][2]==ban[i][3])
	{
	  del[1]=del[2]=del[3]=1;
	  p=ban[i][1];
	}
      if(ban[i][2]>0 && ban[i][2]==ban[i][3] && ban[i][3]==ban[i][4])
	{
	  del[2]=del[3]=del[4]=1;
	  p=ban[i][2];
	}
    
      for(j=0;j<5;j++)
	if(del[j])
	  {
	    ban[i][j]=0;
	    ret += p;
	  }
    }
  return(ret);
}
int solve()
{
  int sum,ret;
  sum=0;
  while(ret=delete3())
    {
      //printf("ret=%d\n",ret);
      //show();
      shrink();
      sum += ret;
      //show();
    }
  return(sum);
}
main()
{
  int i,j,ret;
  while(scanf("%d ",&n) && n)
    {
      for(i=0;i<n;i++)
	for(j=0;j<5;j++)
	  {
	    scanf("%c ",&ban[i][j]);
	    ban[i][j] -= '0';
	  }
      //show();
      ret=solve();
      printf("%d\n",ret);
    }
  return(0);
}
