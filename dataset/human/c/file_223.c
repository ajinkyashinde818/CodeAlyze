#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
  int i;
  int count = 0;
  int n;
  int low_i;
  int low;
  long long int ans = 0;
  long long int a[100000];
  long long int b[100000];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%lld", &a[i]);
  }

  low = llabs(a[0]);
  low_i = 0;

  for(i = 0; i < n; i++){
    if(a[i] < 0){
      b[i] = - a[i];
      count++;
    }
    else{
      b[i] = a[i];
    }

    if(low > b[i]){
      low = b[i];
      low_i = i;
    }
  }

  for(i = 0; i < n; i++){
    if(i == low_i &&  (count = count % 2) != 0){
      ans +=  - b[i];
    }
    else {
      ans += b[i];
    }
  }

  printf("%lld\n", ans);


  return 0;
}
