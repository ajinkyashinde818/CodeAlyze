#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    
    ll Pos = A[0] + A[1];
    ll Neg = -Pos;
    for (int n = 1; n < N-1; ++n) {
        ll PosNew = Pos + A[n+1];
        ll Tmp = Neg + A[n+1];
        if (Tmp > PosNew) PosNew = Tmp;
        
        ll NegNew = Pos - 2*A[n] - A[n+1];
        Tmp = Neg + 2*A[n] - A[n+1];
        if (Tmp > NegNew) NegNew = Tmp;
        
        Pos = PosNew;
        Neg = NegNew;
    }
    
    cout << (Pos > Neg ? Pos : Neg) << endl;

    return 0;
}
