#include<stdio.h>
#define N 200000
#define DEFAULT -1000000000

int main(){
  int n, r[N], i;
  int min, max;

  scanf("%d", &n);

  for(i=0;i<n;i++){
    scanf("%d", &r[i]);
  }

  max = DEFAULT;
  min = r[0];

  for(i=1;i<=n-1;i++){
    if(max < r[i]-min) max = r[i]-min;
    if(min > r[i]) min = r[i];
  }

  printf("%d\n", max);

  return 0;
}
