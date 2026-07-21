#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main() {
    lli n, r;
    cin >> n >> r;
    if(n >= 10) {
        printf("%lld\n", r);
    } else {
        printf("%lld\n", (r+100*(10-n)));
    }

    return 0;
}
