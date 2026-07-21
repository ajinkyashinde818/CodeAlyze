#include <stdio.h>
#include <math.h>

int MaxV(int, int);
int MinV(int);

int x;

main(){
  int n, j, minv, maxv;

  maxv = pow(10, 9) * (-1);

  scanf("%d", &n);
  scanf("%d", &minv);

  for( j = 1; j <= n-1; j++){

    maxv = MaxV(maxv, minv);

    minv = MinV(minv);

  }

  printf("%d\n", maxv);

  return 0;

}

int MaxV(int maxv, int minv){
  scanf("%d", &x);

  if( maxv > x - minv ) return maxv;
  else return x - minv;

}

int MinV(int minv){

  if( minv < x ) return minv;
  else return x;

}
