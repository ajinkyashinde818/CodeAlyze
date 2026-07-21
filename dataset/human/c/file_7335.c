#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define revrep(i,begin,end) for(int i=begin; i>end; i--)
#define lld long long int

int cmpAsc(const void* a, const void* b){
    lld x = *(lld*)a, y = *(lld*)b;
    if(x > y){
        return 1;
    }
    if(x < y){
        return -1;
    }
    return 0;
}

int binarySearch_l(lld* p, int n, lld target){
    int l = 0, r = n-1;
    int m = (l+r+1)/2;
    while(l < r){
        if(*(p + m) <= target){
            l = m;
        }else{
            r = m-1;
        }
        m = (l+r+1)/2;
    }
    return m;
}
int binarySearch_r(lld* p, int n, lld target){
    int l = 0, r = n-1;
    int m = (l+r)/2;
    while(l < r){
        if(target <= *(p + m)){
            r = m;
        }else{
            l = m+1;
        }
        m = (l+r)/2;
    }
    return m;
}

lld calc(lld a){
    return a < 0 ? -1 * a : a;
}

int main(){
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);
    lld shrine[a], temple[b];
    rep(i, 0, a){
        scanf("%lld", &shrine[i]);
    }
    rep(i, 0, b){
        scanf("%lld", &temple[i]);
    }
    qsort(shrine, a, sizeof(lld), cmpAsc);
    qsort(temple, b, sizeof(lld), cmpAsc);
    lld ans[q];
    rep(i, 0, q){
        lld point;
        scanf("%lld", &point);
        lld x  , y  , z;
        lld x_l, y_l, z_l;
        lld buf = LLONG_MAX;
        x = temple[binarySearch_l(temple, b, point)];
        x_l = calc(point - x);
        y = shrine[binarySearch_l(shrine, a, x)];
        y_l = calc(x - y);
        z = shrine[binarySearch_r(shrine, a, x)];
        z_l = calc(x - z);
        x_l += y_l < z_l ? y_l : z_l;
        if(buf > x_l){
            buf = x_l;
        }
        x = temple[binarySearch_r(temple, b, point)];
        x_l = calc(point - x);
        y = shrine[binarySearch_l(shrine, a, x)];
        y_l = calc(x - y);
        z = shrine[binarySearch_r(shrine, a, x)];
        z_l = calc(x - z);
        x_l += y_l < z_l ? y_l : z_l;
        if(buf > x_l){
            buf = x_l;
        }
        x = shrine[binarySearch_l(shrine, a, point)];
        x_l = calc(point - x);
        y = temple[binarySearch_l(temple, b, x)];
        y_l = calc(x - y);
        z = temple[binarySearch_r(temple, b, x)];
        z_l = calc(x - z);
        x_l += y_l < z_l ? y_l : z_l;
        if(buf > x_l){
            buf = x_l;
        }
        x = shrine[binarySearch_r(shrine, a, point)];
        x_l = calc(point - x);
        y = temple[binarySearch_l(temple, b, x)];
        y_l = calc(x - y);
        z = temple[binarySearch_r(temple, b, x)];
        z_l = calc(x - z);
        x_l += y_l < z_l ? y_l : z_l;
        if(buf > x_l){
            buf = x_l;
        }
        ans[i] = buf;
    }
    rep(i, 0, q){
        printf("%lld\n", ans[i]);
    }

    return 0;
}
