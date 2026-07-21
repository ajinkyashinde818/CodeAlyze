#include<stdio.h>
int main(){
  
  int cnt=0;
  int K=0,S=0;
  int X=0,Y=0,Z=0;
  scanf("%d %d", &K,&S);
  
  for(; X <= K; X++){
    Y=0;
      for(; Y <= K; Y++){
          if(S-X-Y >= 0 && S-X-Y <=K){
            cnt++;
          }
      }
  }
  
  printf("%d", cnt);
  
 return 0; 
}
