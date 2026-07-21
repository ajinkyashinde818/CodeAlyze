#include <stdio.h>
#include <stdlib.h>
#define N 200000
int max(int, int);
int min(int, int);

int main(){
  int i, j, n, R[N], maxv, minv;
  scanf("%d",&n);
  if(n < 2 || n > N)exit(1);
  for(i = 0; i <= n - 1; i++){
    scanf("%d",&R[i]);
    if(R[i] < 1 || R[i] > 10*10*10*10*10*10*10*10*10)exit(2);
  }
  minv = R[0];
  maxv = R[1] - R[0];
  for(j = 1; j <= n - 1; j++){
    maxv = max(maxv, R[j] - minv);
    minv = min(minv, R[j]);
  }
  printf("%d\n",maxv);
  return 0;
}

int max(int maxv, int R1){
  if(maxv > R1)return maxv;
  else return R1;
}

int min(int minv, int R2){
  if(minv < R2)return minv;
  else return R2;
}
