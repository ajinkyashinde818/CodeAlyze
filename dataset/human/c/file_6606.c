#include<stdio.h>
#include<stdlib.h>

#define MAX 200000

int main(){
  int n,i,j;
  int R[MAX];
  int maxv,minv;

  scanf("%d",&n);
  if( n < 2 || MAX < n ) exit(2);

  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&R[i]);
    if( R[i] < 1 || 1000000000 < R[i] )
      exit(3);
  }

  maxv=R[1]-R[0];
  minv=R[0];
  for( j = 1 ; j < n ; j++ )
    { 
      if( maxv < R[j]-minv ) maxv = R[j]-minv;
      if( minv > R[j] ) minv = R[j];
  }
  printf("%d\n",maxv);
 
  return 0;
}
