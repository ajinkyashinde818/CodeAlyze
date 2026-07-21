#include <stdio.h>
#include <string.h>

int main(){
  int N,K;
  scanf("%d %d", &N, &K);
  
  int H[N];
  for(int i=0; i<N; i++){
    scanf("%d", &H[i]);
  }
  
  int canRide = 0;
  for(int j=0; j<N; j++){
    if(H[j] >= K) canRide++;
  }
  
  printf("%d", canRide);
}
