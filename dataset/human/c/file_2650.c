#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

int ascending_compare(const void *a, const void *b){
    if (*(int*)a < *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

// array pointer = *a, num of element = n, key = key
long long lower_bound(int *a, long long n, long long key){
    long long ng, mid, ok;
    ng = -1, ok = n-1;
    while (llabs(ok - ng) > 1){
        mid = (ok + ng) / 2;
        if (key <= a[mid]){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    if (a[ok] >= key)return ok;
    return n;
}

//greatest common divisor
unsigned long gcd(unsigned long x, unsigned long y){
    if (y == 0){ 
        return x;
    }else if (x > y){
        return gcd(y, x % y);
    }else{
        return gcd(x, y % x);
    }
}

unsigned long lcm(unsigned long x, unsigned long y){
    unsigned long g = gcd(x, y);
    return x*y/g;
}



long long factorial(int x){
    long long rtn = 1;
    int i;
    for (i = x; i > 1; i--){
        rtn = (rtn*i);
    }
    return rtn;
}




/*unsigned long long pascal[100][100] = {0};
void make_pascal(void){
    for (int i = 0; i < 100; i++){
        pascal[i][0] = 1;
    }
    pascal[1][1] = 1;
    for (int i = 2; i < 100; i++){
        for (int j = 1; j < 100; j++){
           pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j]) % mod;
        }
    }
}*/
long long mod = 1000000007;
//x ^ n
long long mod_pow(long long x, long long n){
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

/*int struct_ascending_compare(const void *p, const void*q){
    return (*(structname *)p) -> member - (*(structname *)q) -> member;
}*/

int a[200005];
int b[200005];
int am[200005];
int bm[200005];
int bit[30];
long long mask;

int mask_ascending_compare(const void *a, const void *b){
    if ((*(int*)a & mask) < (*(int*)b & mask)){
        return -1;
    }else if ((*(int*)a & mask) == (*(int*)b & mask)){
        return 0;
    }else{
        return 1;
    }
}

long long mask_lower_bound(int *a, long long n, long long key){
    long long ng, mid, ok;
    ng = -1, ok = n-1;
    while (llabs(ok - ng) > 1){
        mid = (ok + ng) / 2;
        if (key <= (a[mid] & mask)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    if ((a[ok] & mask) >= key)return ok;
    return n;
}



int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    mask = 0;
    for (int k = 0; k < 30; k++){
        mask += 1 << (k);
        qsort(b, n, sizeof(int), mask_ascending_compare);
        long long tmp = 0;
        for (int i = 0; i < n; i++){
            int lower1 = mask_lower_bound(b, n, (1 << k) - (a[i] & mask));
            int upper1 = mask_lower_bound(b, n, (1 << k)*2LL - (a[i] & mask));
            int lower2 = mask_lower_bound(b, n, (1 << k)*3LL - (a[i] & mask));
            int upper2 = mask_lower_bound(b, n, (1 << k)*4LL - (a[i] & mask));
            bit[k] = ((upper1 - lower1 + upper2 - lower2) % 2 + bit[k]) % 2;
        }
    }

    int ans = 0;
    for (int i = 0; i < 30; i++){
        ans += (1 << i)*bit[i];
    }

    printf("%d\n", ans);

    return 0;
}
