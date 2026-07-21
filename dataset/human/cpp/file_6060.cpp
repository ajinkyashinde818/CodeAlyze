#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000;

typedef long long I64;

I64 pos[NMAX+2], val[NMAX+2], sp[NMAX+2], sp2[NMAX+2];
I64 cost_lef[NMAX+2], cost_rig[NMAX+2];
I64 best_lef[NMAX+2], best_rig[NMAX+2];
I64 best = 0;
I64 N, C;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for( int i = 1;  i <= N;  ++i ) {
        cin >> pos[i] >> val[i];
        sp[i] = sp[i - 1] + val[i];
        cost_rig[i] = sp[i] - pos[i];
        best_rig[i] = max(best_rig[i - 1], cost_rig[i]);
    }
    for( int i = N;  i >= 1;  --i ) {
        sp2[i] = sp2[i + 1] + val[i];
        cost_lef[i] = sp2[i] - (C - pos[i]);
        best_lef[i] = max(best_lef[i + 1], cost_lef[i]);
    }
    best = max(0LL, max(best_lef[1], best_rig[N]));
    for( int i = 1;  i <= N;  ++i ) {
        I64 c_lef = cost_lef[i] + best_rig[i - 1] - (C - pos[i]);
        if( i > 1 )
            best = max(best, c_lef);
        I64 c_rig = cost_rig[i] + best_lef[i + 1] - pos[i];
        if( i < N )
            best = max(best, c_rig);
    }
    cout << best << '\n';
    return 0;
}
