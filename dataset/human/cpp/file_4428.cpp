#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=100005,INF=1<<30;

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

vector<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),B(N),used(N);
    int sub=0;
    map<int,int> MA;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sub^=A[i];
        MA[A[i]]++;
    }
    MA[sub]++;
    for(int i=0;i<N;i++){
        cin>>B[i];
        MA[B[i]]--;
        if(MA[B[i]]<0){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    for(int i=0;i<N;i++){
        if(A[i]==B[i]) used[i]=1;
    }
    
    UF uf;
    uf.init(N);
    
    vector<pair<int,int>> S;
    map<int,int> F;
    for(int i=N-1;i>=0;i--){
        if(used[i]) continue;
        S.push_back(mp(B[i],i));
        F[B[i]]=i;
    }
    sort(all(S));
    
    for(int i=0;i+1<si(S);i++){
        if(S[i].fi==S[i+1].fi){
            uf.unite(S[i].se,S[i+1].se);
        }
    }
    
    for(int i=0;i<N;i++){
        if(used[i]) continue;
        if(F.count(A[i])){
            uf.unite(i,F[A[i]]);
        }
    }
    
    for(int i=0;i<N;i++){
        if(used[i]) continue;
        G[uf.root(i)].push_back(i);
    }
    
    int ans=0;
    
    for(int i=0;i<N;i++){
        if(si(G[i])==0) continue;
        
        vector<int> X,Y;
        for(int a:G[i]){
            X.push_back(A[a]);
            Y.push_back(B[a]);
        }
        
        sort(all(X));
        sort(all(Y));
        
        if(X==Y&&!binary_search(all(X),sub)) ans+=si(G[i])+1;
        else ans+=si(G[i]);
    }
    
    cout<<ans<<endl;
    
}
