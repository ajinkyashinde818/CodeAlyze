#include<stdio.h>
#include<stdlib.h>

int main(){
  long a[100000] = {};
  long absmin = -1; 
  long n = 0;
  long i = 0;
  long long abstotal=0;
  long minuscnt=0;
  scanf("%ld",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
    if(a[i]<0){
      minuscnt++;
    }
    if(absmin == -1 || absmin > labs(a[i])){
      absmin = labs(a[i]);
    }
    abstotal += labs(a[i]);
  }
  if(minuscnt % 2 == 0){
    printf("%lld",abstotal);
  }else{
    printf("%lld",abstotal-2*absmin);
  }
  return 0;
}
