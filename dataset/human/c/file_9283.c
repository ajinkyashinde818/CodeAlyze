#include <stdio.h>

int main(){
  int N, K, J, count = 0;
  scanf("%d", &N);
  scanf("%d", &K);
  int arr[N];
  
  for(int i = 0; i<N; i++){
    arr[i] = scanf("%d", &J);
  	if(J >= K)
      count++;
  }
  printf("%d\n", count);
}
