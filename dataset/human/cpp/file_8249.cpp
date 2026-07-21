#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T,class U> using P = pair<T,U>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

constexpr int si = 600;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    vvec<int> g(N);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vec<int> col(N,1),ans(Q,0);
    int K = (Q+si-1)/si;
    vvec<int> T(K),V(K);
    for(int i=0;i<Q;i++){
        int t,v;
        cin >> t >> v;
        v--;
        int k = i/si;
        T[k].push_back(t);
        V[k].push_back(v);
    }
    
    auto solve = [&](int k,vec<int>& T,vec<int>& V){
        int n = T.size();
        vec<int> check(N,0);
        for(int i=0;i<n;i++) check[V[i]] = 1;
        vvec<int> tree(N);
        vec<int> val = col;
        vec<int> vis(N,-1);
        
        auto comp = [&](auto& self,int cur,int par,int s)->void{
            if(s!=cur){
                val[s] += val[cur];
                val[cur] = 0;
            }
            for(auto& e:g[cur]) if(e!=par && !check[e] && col[e]) self(self,e,cur,s);
        };

        for(int i=0;i<N;i++) if(!check[i] && col[i] && val[i]) comp(comp,i,-1,i);

        vec<int> need(N,0);
        for(int i=0;i<N;i++) need[i] = (check[i] || val[i]);

        auto dfs = [&](auto& self,int cur,int par,int s,vec<int>& v)->void{
            vis[cur] = s;
            for(auto& e:g[cur]) if(e!=par){
                if(need[e]) v.push_back(e);
                else if(col[e]) self(self,e,cur,s,v);
            }
        };

        for(int i=0;i<N;i++) if(!check[i] && val[i]){
            vec<int> v;
            dfs(dfs,i,-1,i,v);
            if(v.size()==1){
                val[v[0]] += val[i];
                val[i] = 0;
                need[i] = false;
            }else{
                for(auto& x:v) tree[i].push_back(x);
            }
        }

        for(int i=0;i<N;i++) if(check[i]){
            for(auto& e:g[i]){
                if(check[e]) tree[i].push_back(e);
                else if(need[vis[e]]) tree[i].push_back(vis[e]);
            }
        }

        auto dfs2 = [&](auto& self,int cur,int par,int q)->void{
            ans[q] += val[cur];
            for(auto& e:tree[cur]) if(e!=par && col[e]) self(self,e,cur,q);
        };

        for(int i=0;i<n;i++){
            if(T[i]==1){
                col[V[i]] ^= 1;
                val[V[i]] += (col[V[i]]? 1:-1);
            }else dfs2(dfs2,V[i],-1,k*si+i);
        }
    };

    for(int k=0;k<K;k++) solve(k,T[k],V[k]);

    for(int i=0;i<Q;i++) if(ans[i]) cout << ans[i] << "\n";
}
