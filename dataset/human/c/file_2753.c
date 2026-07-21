#include <stdio.h>

int main (void){
  
  int K, S;
  
  scanf("%d %d", &K, &S);
  
  int X,Y,Z;
  int count=0;
  
  for (X=0; X<=K; X++){
   for (Y=0; Y<=K; Y++){
       if (0<=S-X-Y && S-X-Y<=K) {count=count+1;}
   }
  }
  
  printf("%d", count);
  
  return 0;
}
