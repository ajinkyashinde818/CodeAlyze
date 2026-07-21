#include<stdio.h>
int minnum(int[], int);

int main(){
  int n, i, j, max, min;
  int R[200000];
  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ ){
    scanf("%d",&R[i]);
  }

  min = R[0];
  max = R[1] - R[0];
  for( i = 1 ; i < n ; ++i ){
    if( max < R[i]-min ) max = R[i]- min;
    if( min > R[i] ) min = R[i];
  }

  printf("%d\n",max);
  return 0;
}
