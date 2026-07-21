#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    scanf("%d", &N);
    ll A[N];
    for(int i = 0; i < N; ++i) scanf("%lld", &A[i]);
    for(int i = 1; i < N; ++i) A[i] += A[i-1];
    ll res = (2e14 + 100);
    for(int i = 0; i < N-1; ++i) {
        ll snuke = A[i];
        ll kuma = A[N-1] - A[i];
        res = min(res, abs(snuke - kuma));
    }
    printf("%lld\n", res);
    return 0;
}
