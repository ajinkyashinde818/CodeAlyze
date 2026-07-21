#include<stdio.h>
#include<stdlib.h>

int main(){
  int n, i, max=-1000000000, min;
  int R[200000];

  scanf("%d",&n);
  if( n<2 || 200000<n ) exit(1);

  min = R[0];
  for( i=0 ; i<n ; i++ ){
    scanf("%d",&R[i]);
    if( R[i]<1 || 1000000000<R[i] ) exit(1);
  }

  min = R[0];
  
  for( i=1 ; i<n ; i++ ){
    if( max < R[i]-min ){
      max = R[i] - min;
    }

    if( min > R[i] ){
      min = R[i];
    }
  }

  printf("%d\n",max);
  return 0;
}
