#include<stdio.h>
#include <math.h>

int main(void){
  int n , m , x;
  scanf("%d %d %d",&n,&m,&x);
  
  int  c[n] , a[n][m];
  
  for(int i = 0;i < n;i ++){
    scanf("%d",&c[i]);
    for(int j = 0;j < m;j ++){
      scanf("%d",&a[i][j]);
    }
  }
  
  int k = (int)pow(2,n);
  int kumi[k][n];
  
  for(int i = 0;i < k;i ++){
     int temp = i;
     int count  = 0;
    while(count < n){
      kumi[i][count] = temp%2;
      temp /= 2;
      count ++;
    }
  }
  
  long X[13] = {0} , C = 0 , min = 9999999;
  
  for(int i = 0;i < k;i ++){
    for(int j = 0;j < n;j ++){
      if(kumi[i][j] == 1){
        for(int l = 0;l < m;l ++){
          X[l] += a[j][l];
        }
        C += c[j];
      }
    }
    for(int p = 0;p < m;p ++){
      if(X[p] < x){
        C = -1;
      }
    }
    if(C >= 0 &&C < min){
      min = C;
    }
    C = 0;
    for(int i = 0;i < m;i ++){
      X[i] = 0;
    }
  }
 if(min == 9999999){
   printf("-1\n");
 }
  else{
  printf("%d\n",min);
  }
  
  return 0;
}
