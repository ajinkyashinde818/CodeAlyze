#include<stdio.h>
#include<math.h>

#define N 200000

int main(void){
  int n;
  int r[N];
  int i;
  int maxv = -1 * 1000000000;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &r[i]);
  }

  int minv = r[0];

  for(i = 1; i <= n - 1; i++){
    if(maxv < r[i] - minv){
      maxv = r[i] - minv;
    }
    if(minv > r[i]){
      minv = r[i];
    }
  }

  printf("%d\n", maxv);

}
