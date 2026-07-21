#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using Graph=vector<vector<int>>;
using T3=pair<pair<int,int>,int>;
const int LOGN=22;
int main(){
    int n;
    cin>>n;
    Graph g(n);
    vector<int> p(n);
    p[0]=0;
    for(int i=0;i+1<n;i++){
        cin>>p[i+1];
        p[i+1]--;
        g[p[i+1]].push_back(i+1);
    }
    vector<vector<int>> dbl(LOGN,vector<int>(n));
    dbl[0]=p;
    for(int i=0;i+1<LOGN;i++){
        for(int j=0;j<n;j++){
            dbl[i+1][j]=dbl[i][dbl[i][j]];
        }
    }
    vector<int> dep(n);
    function<void(int,int)> setDep=[&](int v,int d){
        dep[v]=d;
        for(auto &to:g[v]) setDep(to,d+1);
    };
    setDep(0,0);
    auto LCA=[&](int l,int r){
        if(dep[l]<dep[r]) swap(l,r);
        int upper=dep[l]-dep[r];
        int iter=0;
        while(upper){
            if(upper&1) l=dbl[iter][l];
            upper/=2;
            iter++;
        }
        assert(dep[l]==dep[r]);
        if(l==r) return l;
        for(int i=LOGN-1;i>=0;i--){
            if(dbl[i][l]!=dbl[i][r]){
                l=dbl[i][l];
                r=dbl[i][r];
            }
        }
        return p[l];
    };

    priority_queue<T3,vector<T3>,greater<>> que;
    int t=0;
    auto insert=[&](int x){
        for(auto to:g[x]) que.push({{dep[to],t},to});
    };
    int v=0;
    insert(0);
    
    ll res=0;
    while(!que.empty()){
        int to=que.top().second;que.pop();
        int lca=LCA(v,to);
        int sc=dep[v]-dep[lca]+dep[to]-dep[lca];
        res+=sc;
        insert(to);
        v=to;
        t++;
    }
    cout<<res<<endl;
    return 0;
}
