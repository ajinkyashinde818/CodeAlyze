#include <stdio.h>
 
int max(int a, int b)                   //最大を求める
{  
  if(a>=b)
    return a;
  else
    return b;
}
    
int main(void)
{
  int K,N;
  int i;
  int a[200000];
  int dis[200000];
  int large=0;
  
  do {
 	 scanf("%d %d",&K,&N);
  } while((K < 2 || K > 1000000) || (N < 2 || N > 200000));
 
  for(i=0; N>i; i++){
     if(i == 0){
        do{
          scanf("%d ",&a[i]);
       } while(a[i] >= K);
     }
    else{
    	do{
          scanf("%d ",&a[i]);
    	} while(a[i] >= K || a[i] <= a[i-1]);
    }
  }
  for(i=0; N>i ; i++){
    if(N != i+1)                            //最後の引き算で距離がーになるのを防ぐ
      dis[i] = a[i+1] - a[i];
    else
      dis[i] = (K+a[0]) - a[i];
    large = max(large,dis[i]);
  }
    
  printf("%d",K-large);
  return 0;
}
