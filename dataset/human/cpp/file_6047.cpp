#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

long long MOD = 1000000007;

struct Sushi {
    long long x;
    long long v;
};

int main() {
    
    int N;
    long long C;
    cin >> N >> C;


    long long ans = 0;
    vector<Sushi> V(N);
    for ( int i = 0; i < N; i++ ) {
        long long x,v;
        cin >> x >> v;
        V[i].x = x;
        V[i].v = v;        
    }

    long long vs = 0;
    for ( int i = 0; i < N; i++ ) {
        vs += V[i].v;
        ans = max( ans, vs-V[i].x );
    }
    vs = 0;
    for ( int i = N-1; i >= 0; i-- ) {
        vs += V[i].v;
        ans = max( ans, vs-(C-V[i].x) );
    }

    vector<long long> BR(N), BL(N);
    long long v = V[0].v;
    BR[0] = V[0].v-V[0].x;
    for ( int i = 1; i < N; i++ ) {
        v += V[i].v;
        BR[i] = max( BR[i-1], v-V[i].x );
    }
    v = V[N-1].v;
    BL[N-1] = v-(C-V[N-1].x);
    for ( int i = N-2; i >= 0; i-- ) {
        v += V[i].v;
        BL[i] = max( BL[i+1], v-(C-V[i].x) );
    }

    v = 0;
    for ( int i = 0; i < N-1; i++ ) {
        v += V[i].v;
        ans = max( ans, v - V[i].x*2 + BL[i+1] );
    }
    v = 0;

    for ( int i = N-1; i >= 1; i-- ) {
        v += V[i].v;
        ans = max( ans, v - ( (C-V[i].x)*2 ) + BR[i-1] );
    }
    cout << ans << endl;


    return 0;
}
