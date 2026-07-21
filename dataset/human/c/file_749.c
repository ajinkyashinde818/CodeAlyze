#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define rep(i, n) for(int i = 0; i < n; i++)
#define in_arr(type, a, n) for(int i = 0; i < n; i++) scanf(type, &((a)[i]));
#define ll long long int
#define MOD 1000000007

void merge_sort(int *a, int n){
    if(n < 2) return;
    int mid = n / 2;
    int *left = malloc(sizeof(int) * mid);
    int *right = malloc(sizeof(int) * (n - mid));
    for(int i = 0; i < mid; ++i){
        left[i] = a[i];
    }
    
    for(int i = 0; i < n - mid; ++i){
        right[i] = a[i + mid];
    }
    merge_sort(left, mid);
    merge_sort(right, n - mid);
    for(int i = 0; i < n; ++i){
        printf("%d\t", a[i]);
    }
    printf("\n");
    int li = 0, ri = 0;
    for(int i = 0; i < n; ++i){
        if(li >= mid){
            for(; ri < n - mid; ++ri){
                a[i] = right[ri];
                ++i;
            }
            break;
        }
        
        if(ri >= n - mid){
            for(; li < mid; ++li){
                a[i] = left[li];
                ++i;
            }
            break;
        }
        
        if(left[li] < right[ri]){
            a[i] = left[li];
            li++;
        }else{
            a[i] = right[ri];
            ri++;
        }
    }
    free(left);
    free(right);
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

ll mod_add(ll a, ll b){
    return (a + b) % MOD;
}

ll mod_sub(ll a, ll b){
    return (a - b + MOD) % MOD;
}

ll mod_mul(ll a, ll b){
    return (a * b) % MOD;
}

ll mod_pow(ll a, ll b){
    if(b == 0){
        return 1;
    }else if(b == 1){
        return a;
    }else{
        ll half = mod_pow(a, b / 2);
        return mod_mul(mod_mul(half, half), b % 2 == 0 ? 1 : a);
    }
}

ll mod_inverse(ll a){
    return mod_pow(a, MOD - 2);
}

ll mod_div(ll a, ll b){
    return mod_mul(a, mod_inverse(b));
}

int main(){
    int n;
    scanf("%d", &n);
    int *count;
    count = malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; ++i){
        count[i] = 1;
    }
    char c;
    scanf("%c", &c);
    for(int i = 0; i < n; ++i){
        scanf("%c", &c);
        ++count[c - 'a'];
    }
    ll ret = 1;
    for(int i = 0; i < 26; ++i){
        ret = mod_mul(ret, count[i]);
    }
    printf("%lld\n", mod_sub(ret, 1));
    free(count);
    return 0;
}
