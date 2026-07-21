#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ABC125D
int compare_lli(const void *a, const void *b) {
  long *A=(long long *) a;
  long *B=(long long *) b;
  if(*A>*B) return 1;
  if(*A<*B) return -1;
  return 0;
}
int main(void) {
  int n, k, i, cou=0;
  scanf("%d", &n);
  long long a[n], tmp, sum=0, min=1e10;
  for(i=0; i<n; i++){
    scanf("%lld", &tmp);
    if(tmp<0) cou++;
    a[i]=abs(tmp);
    sum+=a[i];
    if(min>a[i]) min=a[i];
  }
  if(cou%2==0) printf("%lld", sum);
  else printf("%lld", sum-2*min);
  return 0;
}
