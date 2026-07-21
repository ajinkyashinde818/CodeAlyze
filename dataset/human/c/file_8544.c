#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asc(const void *a, const void *b) {
  long long *A = (long long *)a;
  long long *B = (long long *)b;
  if (*A > *B) return 1;
  if (*A < *B) return -1;
  return 0;
}

int main(void){
    long long int n, k, r, i, j, ans=0, po=0, posimin;
    scanf("%lld", &n);
    long long int a[n];
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    qsort(a, sizeof(a) / sizeof(long long int), sizeof(long long int), asc);
    if(a[0]>=0){
        for(i=1; i<n; i++) ans += a[i];
        ans -= a[0];
        printf("%lld\n", ans);
        po = a[0];
        for(i=1; i<n-1; i++){
            printf("%lld %lld\n", po, a[i]);
            po = po - a[i];
        }
        printf("%lld %lld", a[n-1], po);
    }else if(a[n-1]<=0){
        for(i=0; i<n-1; i++) ans -= a[i];
        ans += a[n-1];
        printf("%lld\n", ans);
        po = a[n-1];
        for(i=n-2; i>=0; i--){
            printf("%lld %lld\n", po, a[i]);
            po = po - a[i];
        }
    }else{
        for(i=0; i<n; i++){
            if(a[i]>0){
                posimin = i;
                break;
            }
        }
        for(i=0; i<n; i++) ans += abs(a[i]);
        printf("%lld\n", ans);
        po = a[posimin-1];
        for(i=posimin; i<n-1; i++){
            printf("%lld %lld\n", po, a[i]);
            po = po - a[i];
        }
        printf("%lld %lld\n", a[n-1], po);
        po = a[n-1] - po;
        for(i=posimin-2; i>=0; i--){
            printf("%lld %lld\n", po, a[i]);
            po = po - a[i];
        }
    }
    
}
