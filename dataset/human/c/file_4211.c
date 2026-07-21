#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ABC129C
int main(void) {
  long long n, m, k, i,  tmp,  cou=1,mod=1e9+7, pre=0;
  scanf("%lld %lld", &n, &m);
  long long per[n+1],a[m+1];
  per[0]=1, per[1]=1,a[0]=-1;
  for(i=1;i<=m;i++)scanf("%lld",&a[i]);


  for(i=2; i <= n; i++){
    per[i]=(per[i - 1] + per[i - 2]) % mod;
    //printf("per[%lld]=%lld\n", i, per[i]);
  }
  i=1;

  while(i <= m){
    if(a[i] - a[i-1] == 1){
      printf("0");
      return 0;
    }
    cou=(cou * per[a[i] - a[i-1] - 2]) % mod;
    //printf("%4lld --- %10lld --- %10lld\n",a[i] - a[i-1] - 2,per[a[i] - a[i-1] - 2],cou);
    i++;
  }
  cou=(cou*per[n-a[m]-1])%mod;
  printf("%lld", cou);
}
