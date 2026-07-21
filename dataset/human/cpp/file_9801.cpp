#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 

const int MOD = 1000000007;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    vector<int> count(26);
    rep(i, N) {
        ++count[S[i]-'a'];
    }

    LL ans = 1;
    rep(i, 26) {
        ans = (ans * (count[i]+1)) % MOD;
    }

    ans = (ans + MOD -1) % MOD;    

    cout << ans << endl;

    return 0;
}
