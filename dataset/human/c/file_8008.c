#include<stdio.h>
#define MAX 1000002
#define MOD 1000000007

long long fac[MAX], finv[MAX], inv[MAX];

void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long f(int n1, int n2){
    return fac[n1+n2] * (finv[n1] * finv[n2] % MOD) % MOD;
}

int main()
{
  int x, y, a=0, b=0;
  scanf("%d %d", &x, &y);
  init();

  for(int i=0; i<=MAX; i++){
    int j = x - 2*i;
    if(y == i+2*j){
      a = i;
      b = j;
    }
  }

  if((x+y)%3 != 0){
    printf("0");
    return 0;
  }

  if(a<0 || b<0){
    printf("0");
    return 0;
  }

  if(a==0 && b==0){
    printf("0");
    return 0;
  }

  long long ans;
  ans = f(a, b);
  printf("%lld", ans);
  return 0;
}
