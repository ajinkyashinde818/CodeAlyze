#include<stdio.h>

int main(){
  int N,i,ct = 0;
  long long int sum = 0,min = 2000000000,a;
  scanf("%d",&N);
  for(i = 0;i < N;i++){
    scanf("%lld",&a);
    if(a < 0){
      a = -a;
      ct = 1-ct;
    }
    if(a == 0){
      ct = -1;
    }
    if(a < min){min = a;}
    sum += a;
  }
  if(ct == 1){sum -= min*2;}
  printf("%lld\n",sum);
  return 0;
}
