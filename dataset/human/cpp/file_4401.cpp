#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

    UnionFind(int n=0){
        if(n>0) initialize(n);
    }

    void initialize(int n){
        par.resize(n);
        rank.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]){
            par[x] = y;
            sz[y] += sz[x];
        }else{
            par[y] = x;
            sz[x] += sz[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    int N, A[100001], B[100001];
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];

    map<int, int> mpA, mpB, mpV;
    A[N] = B[N] = 0;
    for(int i=0; i<N; i++){
        mpA[A[i]]++;
        mpB[B[i]]++;
        A[N] ^= A[i];
        B[N] ^= B[i];
    }
    mpA[A[N]]++;
    mpB[B[N]]++;
    for(auto p : mpA){
        mpV[p.first] = mpV.size() - 1;
        if(p.second != mpB[p.first]){
            cout << -1 << endl;
            return 0;
        }
    }
    
    int ans = -1;
    UnionFind uf(mpV.size());
    for(int i=0; i<N; i++){
        if(A[i] != B[i]){
            ans++;
            uf.unite(mpV[A[i]], mpV[B[i]]);
        }
    }
    uf.unite(mpV[A[N]], mpV[B[N]]);

    bitset<100001> ok;
    for(int i=0; i<=N; i++){
        if(i<N && A[i] == B[i]) continue;
        if(!ok[uf.find(mpV[A[i]])]) ans++;
        ok[uf.find(mpV[A[i]])] = 1;
    }

    cout << ans << endl;
    return 0;
}
