#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

int main(){
  int n,i,flag = 0;
  int cnt = 0;
  ll x;
  ll sum = 0;
  ll min = 100100100;

  scanf("%d", &n);

  for(i = 0;i < n;i++){
    scanf("%lld", &x);
    sum += abs(x);

    if(x == 0) flag = 1;

    if(x < 0) cnt++;

    if(min > abs(x)) min = abs(x);
  }


  if((cnt % 2) == 0) flag = 1;

  if(flag == 1) printf("%lld\n", sum);

  else printf("%lld\n", sum - 2*min);


  return 0;
}
