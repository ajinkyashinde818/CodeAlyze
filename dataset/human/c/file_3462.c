#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
typedef long long ll;
 
  int a[200008];
  int v[200008];
 
int main(){
  ll k;
  int n;
  int i,j;
  int t;
  int sum1 = 0;
  int sum2 = 0;
  int now;
 
  scanf("%d %lld", &n, &k);
 
  for(i = 1;i <= 200000;i++) v[i] = 0;
 
  for(i = 1;i <= n;i++) scanf("%d", &a[i]);
 
  now = 1;
 
  while(1){
    if(v[now] == 1){
      t = now;
      break;
    }
 
    else{
      v[now] = 1;
      now = a[now];
      sum1++;
    }
  }

  if(k < sum1){
    now = 1;
    while(k){
      now = a[now];
      k--;
    }

    printf("%d\n", now);
    return 0;
  }
 
  now = 1;
  while(now != t){
    now = a[now];
    sum2++;
  }
 
  sum1 = sum1 - sum2;
 
  k = (k - sum2) % sum1;
 
  now = t;
  while(k > 0){
    now = a[now];
    k--;
  }
 
  printf("%d\n", now);
 
  return 0;
}
