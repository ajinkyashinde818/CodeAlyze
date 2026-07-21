#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}

template<typename T> class segtree1 {
private:
    int n,sz;
    vector<pair<T, int> > node;
public:
    segtree1(const vector<T>& v) : n(1), sz((int)v.size()){
        while(n < sz) n *= 2;
        node.resize(2*n, make_pair(numeric_limits<T>::min(), sz));
        for(int i = 0; i < sz; i++){
            node[i+n] = make_pair(v[i], i);
        }
        for(int i=n-1; i>=1; i--){
            node[i] = max(node[2*i], node[2*i+1]);
        }
    }
    void update(int k, T a)
    {
        node[k+n] = make_pair(a, k);
        k += n;
        while(k>>=1){
            node[k] = max(node[2*k], node[2*k+1]);
        }
    }
    pair<T, int> query(int a,int b,int k=0,int l=0,int r=-1)
    {
        pair<T, int> res1 = make_pair(numeric_limits<T>::min(), sz);
        pair<T, int> res2 = make_pair(numeric_limits<T>::min(), sz);
        a += n, b += n;
        while(a != b){
            if(a % 2) res1 = max(res1, node[a++]);
            if(b % 2) res2 = max(res2, node[--b]);
            a >>= 1, b>>= 1;
        }
        return max(res1, res2);
    }
    void print()
    {
        for(int i = 0; i < sz; i++){
            pair<T, int> p;
            p = query(i,i+1);
            cout << "st[" << i << "]: " << p.first << " " << p.second << endl;
        }
    }
};
template<typename T> class segtree2 {
private:
    int n,sz;
    vector<pair<T, int> > node;
public:
    segtree2(const vector<T>& v) : n(1), sz((int)v.size()){
        while(n < sz) n *= 2;
        node.resize(2*n, make_pair(numeric_limits<T>::min(), -sz));
        for(int i = 0; i < sz; i++){
            node[i+n] = make_pair(v[i], -i);
        }
        for(int i=n-1; i>=1; i--){
            node[i] = max(node[2*i], node[2*i+1]);
        }
    }
    void update(int k, T a)
    {
        node[k+n] = make_pair(a, -k);
        k += n;
        while(k>>=1){
            node[k] = max(node[2*k], node[2*k+1]);
        }
    }
    pair<T, int> query(int a,int b,int k=0,int l=0,int r=-1)
    {
        pair<T, int> res1 = make_pair(numeric_limits<T>::min(), -sz);
        pair<T, int> res2 = make_pair(numeric_limits<T>::min(), -sz);
        a += n, b += n;
        while(a != b){
            if(a % 2) res1 = max(res1, node[a++]);
            if(b % 2) res2 = max(res2, node[--b]);
            a >>= 1, b>>= 1;
        }
        return max(res1, res2);
    }
    void print()
    {
        for(int i = 0; i < sz; i++){
            pair<T, int> p;
            p = query(i,i+1);
            cout << "st[" << i << "]: " << p.first << " " << p.second << endl;
        }
    }
};
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>cnt(n + 1);
    rep(i,n){
        int x;
        cin >> x;
        cnt[x]++;
    }
    segtree1<int> seg1(cnt);
    rep(i,n+1)cnt[i] = 0;
    rep(i,n){
        int x;
        cin >> x;
        cnt[x]++;
    }
    segtree2<int> seg2(cnt);
    vector<pii> ans;
    rep(_,n){
        auto x = seg1.query(1, n + 1);
        auto y = max(seg2.query(0, x.second), seg2.query(x.second + 1, n + 1));
        if(y.first == 0){
            cout << "No" << "\n";
            return 0;
        }
        seg1.update(x.second, x.first - 1);
        seg2.update(-y.second, y.first - 1);
        ans.emplace_back(x.second, -y.second);
    }
    sort(ans.begin(), ans.end());
    cout << "Yes" << "\n";
    rep(i,n){
        cout << ans[i].second << " \n"[i == n - 1];
    }
}
