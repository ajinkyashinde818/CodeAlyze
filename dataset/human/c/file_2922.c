#include<stdio.h>
int main(){
  int K, S;
  int X, Y, Z;
  int cnt=0;
  scanf("%d %d", &K, &S);
  for(X=0; X<=K; X++){
     for(Y=0; Y<=S-X && Y<=K; Y++){
     	Z=S-X-Y;
        if(Z<=K)
          cnt++;
     }
  }
  printf("%d\n", cnt);
  return 0;
}
