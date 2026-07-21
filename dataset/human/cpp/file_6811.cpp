// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;
 
int main() {
    int N; scanf("%d", &N);

    vector<int> cnt(N+1), cntB(N+1);
    vector<int> A(N), B(N);
    vector< set<int> > idx(N+1);
    
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
        cnt[ A[i] ]++;
        idx[ A[i] ].emplace(i);
    }
    for(int i=0; i<N; i++) {
        scanf("%d", &B[i]);
        cnt[ B[i] ]++;
        cntB[ B[i] ]++;
    }

    for(int i=0; i<=N; i++) {
        if(cnt[i] > N) {
            puts("No");
            return 0;
        }
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](auto x, auto y) {
            return cnt[x] > cnt[y];
        });

    
    vector<int> ans(N, -1);
    set<int> S;
    for(int i=0; i<N; i++) S.emplace(i);
    
    for(int i=0; i<N; i++) {
        // for(int j=0; j<N; j++) fprintf(stderr, "%d%c", ans[j], " \n"[j + 1 == N]);
        
        if(i == 0 or B[i-1] != B[i]) {
            for(auto j : idx[ B[i] ]) {
                S.erase(j);
            }
        }

        if(S.empty()) {
            assert(idx[ B[i] ].size() > 0);
            int k = *idx[ B[i] ].begin();
            // fprintf(stderr, "same %d %d\n", i, k);
            ans[k] = B[i];
            idx[ B[i] ].erase(k);
            S.erase(k);
        }
        else {
            int k = *S.rbegin();
            ans[k] = B[i];
            idx[ A[k] ].erase(k);
            S.erase(k);
        }

        if(i == N-1 or B[i] != B[i+1]) {
            for(auto j : idx[ B[i] ]) {
                if(ans[j] == -1) S.emplace(j);
            }
        }
    }

    set<int> match;
    for(int i=0; i<N; i++) {
        assert(ans[i] != -1);
        if(A[i] == ans[i]) {
            match.emplace(i);
        }
    }

    while(match.size()) {
        if(match.size() == 1) break;
        int x = *match.begin(), y = *match.rbegin();
        if(A[x] == A[y]) break;
        swap(ans[x], ans[y]);
        match.erase(x);
        match.erase(y);
    }

    while(match.size()) {
        int x = *match.begin();
        int y = rand() % N;
        if(ans[x] == A[y]) continue;
        if(ans[y] == A[x]) continue;
        swap(ans[x], ans[y]);
        match.erase(x);
    }
    
    puts("Yes");
    for(int i=0; i<N; i++) printf("%d%c", ans[i], " \n"[i + 1 == N]);
    return 0;
}
