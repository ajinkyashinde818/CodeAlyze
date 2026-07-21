#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
int main(){

  int N;
  scanf("%d",&N);
  std::vector<long long > A(N);
  int negative_sign_num = 0;
  long long abs_min = 1000000001;
  long long sum = 0;
  for (int i=0; i<N; i++){
    scanf("%lld",&A[i]);
    sum += abs(A[i]);
    abs_min = std::min(abs_min,abs(A[i]));
    if (A[i]<0){
      negative_sign_num++;
    }
  }
  if (abs_min==0){
    printf("%lld\n",sum);
  } else if (negative_sign_num%2==0){
    printf("%lld\n",sum);
  } else {
    printf("%lld\n",sum-2*abs_min);
  }
  
  return 0;
}
