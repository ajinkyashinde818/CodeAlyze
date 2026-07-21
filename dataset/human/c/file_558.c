#include<stdio.h>
long long ll_abs(long long a){
  if(a < 0){
    return -a;
  }else{
    return a;
  }
}
    
int main(){
  long long n = 0;
  long long a[200000] = {};
  long long i = 0;
  long long sum = 0;
  long long lsum = 0;
  long long diff = 0;
  long long min = -1;
  
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&a[i]);
    sum += a[i];
  }
  for(i=0;i<n-1;i++){
    lsum += a[i];
    diff = ll_abs(lsum - (sum - lsum));
    if(diff < min || min == -1){
      min = diff;
    }
  }
  printf("%lld",min);
  return 0;
}
