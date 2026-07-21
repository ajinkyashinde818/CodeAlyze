#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N;
    cin >> N;
    ll res = 0;
    ll Amin = numeric_limits<ll>::max();
    ll Ai;
    int n_minus = 0;
    for(int i=0;i<N;i++){
        cin >> Ai;
        res += abs(Ai);
        Amin = min(Amin, abs(Ai));
        if(Ai < 0) n_minus++;
    }
    if(n_minus%2==1) res -= 2 * Amin;
    cout << res << endl;

    return 0;
}
