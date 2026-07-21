#include <stdio.h>
 
void Set(int a[3], int max, int mid, int min){
  a[0] = max;
  a[1] = mid;
  a[2] = min;
}
 
int Count(int a[3], int N){
  int i, j, I, J, K, c;
  c = 0;
  for(i = N / a[0];i >= 0;i--){
    I = i * a[0];
    for(j = (N - I) / a[1];j >= 0;j--){
      J = j * a[1];
      K = N - I - J;
      if(K % a[2] == 0) c++;
    }
  }
  return c;
}
 
int main(void){
  int R, G, B, N;
  int a[3];
  scanf("%d %d %d %d", &R, &G, &B, &N);
  if(R > G){
    if(G > B) Set(a, R, G, B);
    else{
      if(R > B) Set(a, R, B, G);
      else Set(a, B, R, G);
    }
  }else{
    if(R > B) Set(a, G, R, B);
    else{
      if(G > B) Set(a, G, B, R);
      else Set(a, B, G, R);
    }
  }
  printf("%d\n", Count(a, N));
  return 0;
}
