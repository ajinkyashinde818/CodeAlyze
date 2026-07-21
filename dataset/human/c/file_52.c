#include<stdio.h>

int main(){
  int R, G, B, N;
  scanf("%d %d %d %d", &R, &G, &B, &N);

  int r;

  int sum;

  int rmax = N/R;

  int ans = 0;

  for(r = 0; r <= rmax; r++){
    sum = R * r;
    while(sum <= N){
      if((N - sum) % B == 0) ans++;
      sum += G;
    }
  }

  printf("%d\n", ans);

  return 0;
}
