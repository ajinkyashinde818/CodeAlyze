#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true; // vを訪問済みにする
    
    for(auto next_v: G[v]){
        if(seen[next_v]) continue; // next_vが探索済みならスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main(){

    int n, r;
    cin >> n >> r;
    int nr;
    if(n >= 10){
        nr = r;
    }
    else{
        nr = r+100*(10-n);
    }
    cout << nr << endl;

    return 0;
}
