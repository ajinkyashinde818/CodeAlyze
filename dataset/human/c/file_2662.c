//
//  Stop. Otherwise...cpp
//  National Olympiad in Informatics in Provinces
//
//  Created by 黄子齐 on 2019/7/25.
//  Copyright © 2019 黄子齐. All rights reserved.
//

#include <stdio.h>
#define int long long
const int N = 4e3+10;
const int mod = 998244353;
int n, k;
int pw[N], c[N][N];
inline int C(int a, int b) {
//    printf("C:%lld %lld %lld\n", a, b, c[a][b]);
    if (b>a||b<0) {
        return 0;
    }
//    printf("%lld %lld %lld\n", a, b, c[a][b]);
    return c[a][b];
}
inline int calc(int a, int b) {
    return C(a+b-1, a-1);
}
inline int work(int val, int n, int k) {
    int sum = 0;
    int lim = (val<=k+1?(val)>>1:(k)-(val>>1));
//    printf("lim:%lld %lld %lld\n", val, k, lim);
    for (int j=0; j<=lim; j++) { //可一个都不选
//        printf("%lld\n", j);
        sum = (sum+pw[j]*C(lim, j)%mod*calc(k-2*lim+j, n-j)%mod) % mod; //可重复选
    }
//    printf("%lld\n", sum);
    return sum;
}
signed main() {
//    freopen("mytestdata.in", "r", stdin);
    pw[0] = 1;
    for (int i=1; i<N; i++) {
        pw[i] = (pw[i-1]<<1) % mod;
    }
    c[0][0] = 1;
    for (int i=1; i<N; i++) {
        c[i][0] = 1;
    }
    for (int i=1; i<N; i++) {
        for (int j=1; j<=i; j++) {
            c[i][j] = (c[i-1][j-1]+c[i-1][j]) % mod;
        }
    }
    scanf("%lld%lld", &k, &n);
    for (int i=2; i<=2*k; i++) {
        int ans = 0;
        if (i&1) {
            ans = (ans+work(i, n, k))%mod;
        } else {
            ans = ((ans+work(i-1, n, k-1))%mod+work(i-1, n-1, k-1))%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
