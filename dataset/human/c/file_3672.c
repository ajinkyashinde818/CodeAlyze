#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int acnt[100001];
int bcnt[100001];

int main(){
  int a,b;
  int i;
  long long ans = 1;

  scanf("%d %d", &a, &b);

  for(i = 0;i < 100001;i++){
    acnt[i] = 0;
    bcnt[i] = 0;
  }

  for(i = 2;i <= a;i++){
    while(a % i == 0){
      acnt[i]++;
      a /= i;
    }
    if(a == 1) break;
  }
  acnt[a]++;

  for(i = 2;i <= b;i++){
    while(b % i == 0){
      bcnt[i]++;
      b /= i;
    }
    if(b == 1) break;
  }
  bcnt[b]++;

  for(i = 2;i <= 100000;i++){
    if(acnt[i] != 0 || bcnt[i] != 0){
      if(acnt[i] > bcnt[i]) ans = ans*pow(i,acnt[i]);

      else ans = ans*pow(i,bcnt[i]);
    }
  }

  printf("%lld\n", ans);

  return 0;
}
