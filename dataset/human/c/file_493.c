#include <stdio.h>
long long int zet(long long int a){
  if(a > 0){
    return a;
  }
  return -a;
}
long long int min(long long int a,long long int b){
  if(a > b){
    return b;
  }
  return a;
}
int main(){
  long long int i,n,sum = 0,mini = -1,bsum = 0;
  scanf("%lld",&n);
  long long int a[n];
  for(i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    sum += a[i];
  }
  for(int i = 0;i < n - 1;i++){
    bsum += a[i];
    if(mini < 0){
      mini = zet(sum - 2 * bsum);
    }else{
      mini = min(mini,zet(sum - 2 * bsum));
    }
  }
  printf("%lld\n",mini);
  return 0;
}
