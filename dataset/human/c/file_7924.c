/*
  AOJ 2265
  Title:Programming Contest Challenge Book
  @kankichi573
*/
#include <stdio.h>
#define max(x,y) (((x)>(y))?(x):(y))

int N;
long long a[100000];

char table[9][6]={{0,1,3,2,4,5},
		  {0,1,4,2,3,5},
		  {0,1,5,2,3,4},
		  {0,2,3,1,4,5},
		  {0,2,4,1,3,5},
		  {0,2,5,1,3,4},
		  {0,3,4,1,2,5},
		  {0,3,5,1,2,4},
		  {0,4,5,1,2,3}};
		 
int is_triangle(long long a1,long long a2,long long a3)
{
  return (a1<a2+a3) && (a2<a3+a1) && (a3<a1+a2);
}


int compare_ll(const void *a, const void *b)
{
  if( *(long long *)a > *(long long *)b)
    return(-1);
  if( *(long long *)a < *(long long *)b)
    return(1);
  if( *(long long *)a == *(long long *)b)
    return(0);
}
long long solve(int start,int tri_no,int n,long long acc) 
{
#ifdef DEBUG
  printf("%d %d %d %lld|",start,tri_no,n,acc);
#endif
  if(tri_no==2)
    return(acc);
  if(n < (2-tri_no)*3)
    return(0);
  if(is_triangle(a[start],a[start+1],a[start+2]))
    return(solve(start+3,tri_no+1,n-3,acc+a[start]+a[start+1]+a[start+2]));
  else
    return(solve(start+1,tri_no,n-1,acc));
}
long long solve2()
{
  int i,j,k;
  long long ret;

  ret=0;
  for(i=0;i<N-6;i++)
    for(j=0;j<9;j++)
      {
	if(is_triangle(a[i+table[j][0]],
		       a[i+table[j][1]],
		       a[i+table[j][2]]) &&
	   is_triangle(a[i+table[j][3]],
		       a[i+table[j][4]],
		       a[i+table[j][5]]))
       
	  {
	    for(k=0;k<6;k++)
	      ret += a[i+k];
	    //printf("s2=%d\n",i);
	    return(ret);
	  }
      }
  return(0);
}
main()
{
  int i;
  long long ret,ret1;
  scanf("%d",&N);
  for(i=0;i<N;i++)  
    scanf("%lld",&a[i]);
  qsort(a,N,sizeof(long long),compare_ll);
#ifdef DEBUG
  for(i=0;i<N;i++)  
    printf(" %lld\n",a[i]);
  for(i=0;i<N-1;i++)
    printf("[%d] %lld\n",i,a[i]-a[i+1]-a[i+2]);
#endif
  
  ret=solve(0,0,N,0); // 3ren * 2
  ret1=solve2();      // 6ren
  printf("%lld\n",max(ret,ret1));
  return(0);
}
