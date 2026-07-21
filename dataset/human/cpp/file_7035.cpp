#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <assert.h>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto &&i : A) scanf("%d", &i);
    for (auto &&i : B) scanf("%d", &i);
    vector<int> cnt(n+1);
    for (int i = 0; i < n; ++i) {
        cnt[A[i]]++;
        cnt[B[i]]++;
    }
    for (int i = 0; i <= n; ++i) {
        if(cnt[i] > n){
            puts("No");
            return 0;
        }
    }
    auto X = A;
    vector<vector<int>> AA(n+1);
    for (int i = 0; i < n; ++i) {
        AA[A[i]].emplace_back(i);
    }
    puts("Yes");
    vector<int> ord(n+1);
    iota(ord.begin(),ord.end(), 0);
    sort(ord.begin(),ord.end(), [&](int x, int y){ return cnt[x] > cnt[y]; });
    vector<int> ordinv(n+1);
    for (int i = 0; i <= n; ++i) {
        ordinv[ord[i]] = i;
    }
    sort(A.begin(),A.end(), [&](int x, int y){ return ordinv[x] > ordinv[y]; });
    sort(B.begin(),B.end(), [&](int x, int y){ return ordinv[x] > ordinv[y]; });

    deque<int> Q1, Q2, Q3, Q4;
    int mode = 0;
    for (auto &&i : ord) {
        if(!cnt[i]) break;
        while(Q1.size()+Q2.size() < 2*n){
            if(!mode){
                if(!B.empty() && B.back() == i && Q1.size()+Q2.size() < n){
                    B.pop_back();
                    Q2.emplace_back(i);
                }else if(!A.empty() && A.back() == i && Q1.size()+Q2.size() < n){
                    A.pop_back();
                    Q1.emplace_back(i);
                }else if(Q1.size()+Q2.size() == n) {
                    mode = 1;
                }else break;
            }else {
                if(!A.empty() && A.back() == i){
                    A.pop_back();
                    Q3.emplace_front(i);
                }else if(!B.empty() && B.back() == i){
                    B.pop_back();
                    Q4.emplace_front(i);
                }else break;
            }
        }
    }
    while(!Q3.empty()){
        Q1.emplace_back(Q3.front());
        Q3.pop_front();
    }
    while(!Q4.empty()){
        Q2.emplace_back(Q4.front());
        Q4.pop_front();
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int a = AA[Q1.front()].back(); AA[Q1.front()].pop_back();
        ans[a] = Q2.back();
        Q1.pop_front(); Q2.pop_back();
    }
    for (int i = 0; i < n; ++i) {
        if(X[i] == ans[i]){
            for (int j = 0; j < n; ++j) {
                if(X[j] != ans[i] && X[i] != ans[j]){
                    swap(ans[i], ans[j]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}
