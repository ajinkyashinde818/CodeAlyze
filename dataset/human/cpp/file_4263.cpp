#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    int sa = 0;
    int sb = 0;
    rep(i,n){
        sa^=a[i];
        sb^=b[i];
    }
    a.push_back(sa);
    b.push_back(sb);
    n++;
    map<int,int>mpa,mpb;
    map<int,int>num;
    int aaa = 0;
    rep(i,n){
        if((a[i]!=b[i]||i==n-1)&&num.find(a[i])==num.end()){
            num[a[i]] = aaa;
            aaa++;
        }
        mpa[a[i]]++;
        mpb[b[i]]++;
    }
    for(auto x:mpa){
        if(x.second!=mpb[x.first]){
            cout << -1 << endl;
            return 0;
        }
    }
    UnionFind uf(aaa);
    int c = 0;
    map<int,multiset<int> >mp;
    rep(i,n){
        if(a[i]!=b[i]||i==n-1){
            if(i!=n-1)c++;
            uf.unite(num[a[i]],num[b[i]]);
            mp[b[i]].insert(a[i]);
        }
    }
    set<int> st; 
    rep(i,aaa){
        st.insert(uf.find(i));
    }
    int k = st.size();
    if(c==0){
        cout << 0 << endl;
    }else{
        int p = sa;
        int res = 0;
        // cerr << c << endl;
        // while(!mp.empty()){
        //     //cerr << p << endl;
        //     if(mp.find(p)!=mp.end()){
        //         //cerr << "Test" << endl;
        //         auto& st = mp[p];
        //         auto x = st.begin();
        //         res++;
        //         int pre = p;
        //         p = *  x;
        //         st.erase(x);
        //         //cerr << p << " " << st.size() << endl;
        //         if(st.size()==0){
        //             mp.erase(pre);
        //         }
        //         //cerr << "Test" << endl;
        //     }else{
        //         //cerr << "test" << endl;
        //         auto st = mp.begin();
        //         auto x = (*st).second.begin();
        //         //cerr <<(*st).first << " " << (*st).second.size() << " " << *x << endl;
        //         res++;
        //         mp[(*st).first].insert(p);
        //         p = *x;
        //         (*st).second.erase(x);
        //         if((*st).second.size()==0){
        //             mp.erase(st);
        //         }
        //         //cerr << "test" << endl;
        //     }
        //     //cerr << mp.size() << endl;
        // }
        cout << c+k-1 << endl;
        
    }
    return 0;
}
