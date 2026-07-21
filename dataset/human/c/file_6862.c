/*
  AOJ 0098
  Title:Maximum sum of sequence
  @kankichi573
  2014/3/1 RTE
*/
#include <stdio.h>
#include <limits.h>
#define max(x,y) (((x)>(y))?(x):(y))
int N;
int array[100][100];
int row_sum[100][100][100];
void calc_row_sum()
{
  int i,j,k,s;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      {
	s=0;
	for(k=0;k<=N-j;k++)
	  {
	    s += array[i][j+k];
	    row_sum[i][j][k]=s;
	  }
      }
}
dump()
{
  int i,j,k;
  for(i=0;i<N;i++)
    {
    for(j=0;j<N;j++)
      {
	for(k=0;k<N-j;k++)
	  printf("%02d|",row_sum[i][j][k]);
	printf("|");
      }
    printf("\n");
    }
}
int calc_matrix_sum(int top,int left,int height,int width)
{
  int i,ret=0;
  for(i=top;i<=top+height;i++)
    ret+=row_sum[i][left][width];
  return(ret);
}
main()
{
  int i,j,k,l,max_,v;
  scanf("%d ",&N);
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      scanf("%d",&array[i][j]);

  calc_row_sum();
  //dump();
  max_=INT_MIN;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      for(k=0;k<=N-1-i;k++)
	for(l=0;l<=N-1-j;l++)
	  if(max_ < (v=calc_matrix_sum(i,j,k,l)))
	    {
	      //printf("%d %d %d %d:%d\n",i,j,k,l,v);
	      max_=v;
	    }
  printf("%d\n",max_);
  return(0);
}
