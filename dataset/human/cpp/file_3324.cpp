#include<bits/stdc++.h>
using namespace std;

int cnt;
long long sum;
int mi = 1e9 + 7;

signed main() {

    int n;
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
        int a;
        scanf("%d", &a);
        if ( a < 0 ) cnt++;
        a = abs(a);
        if ( a < mi ) {
            mi = a;
        }
        sum += a;
    }
    if ( 1 & cnt ) {
        sum -= mi*2;
    }
    printf("%lld\n", sum);

    return 0;
}
