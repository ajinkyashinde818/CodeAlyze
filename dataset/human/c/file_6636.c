#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  scanf("%d", &n);
//  int *R;
//  R = (int *)malloc(sizeof(int) * n);
  int t;
  int max = 0, def = 1000000000;
  for(t = 0; t < n; t++){
    int R;
    scanf("%d", &R);
    if(t == 1)
      max = R - def;
    if(R < def)
      def = R;
    else
      if(R - def > max)
	max = R - def;
  }
  printf("%d\n", max);
  return 0;
}
