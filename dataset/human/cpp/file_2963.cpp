#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b){return b == 0 ? a : GCD(b, a % b);}


int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, zero = 1, parity = 0;
    long long s = 0, lowest = 2e9;

    cin >> n;

    for(int i = 0; i < n; ++i){
        long long j;
        cin >> j;
        if(j < 0LL){
            parity ^= zero;
        } else if(j == 0LL){
            zero = 0;
            parity = 0;
        }
        lowest = min(lowest, (j < 0LL ? -j : j));
        if(j > 0)
            s += j;
        else
            s -= j;
    }

    if(parity == 1)
        s -= lowest * 2;

    cout << s;

    return 0;
}
