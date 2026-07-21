#include<stdio.h>
#define MOD (1000000000+7)
#define MAX (1000000*2+5)
long fac[MAX];
long inv[MAX];
long finv[MAX];

void COMinit(){
    fac[0]=1;
    fac[1]=1;
    finv[0]=1;
    finv[1]=1;
    inv[1]=1;
    for(long i=2;i<MAX;i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

long COM(long n,long k){
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
  int x,y;
  scanf("%d %d",&x,&y);
  if((2*y-x)%3!=0 || (2*x-y)%3!=0)
      printf("0");
  else{
      long n=(2*y-x)/3;
      long m=(2*x-y)/3;
      if(n<0 || m<0)
        printf("0");
      else{
        COMinit();
        printf("%ld\n",COM(n+m,n));
      }
  }
  return 0;
}
