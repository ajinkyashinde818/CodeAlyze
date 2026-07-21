#include<bits/stdc++.h>
using namespace std;

int xorv(const vector<int>& v){
    int res=0;
    for(auto e:v){
        res^=e;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    if(a==b){
        cout<<0<<endl;
        return 0;
    }    
    int xa=xorv(a);
    int xb=xorv(b);
    multiset<int> as(a.begin(),a.end());
    multiset<int> bs(b.begin(),b.end());
    bool isneg=(as!=bs); 
    as.insert(xa);
    bs.insert(xb);
    if(as!=bs) cout<<-1<<endl;
    else{
        int res=0;
        map<int,set<int>> s;
        map<int,int> par;
        for(int i=0;i<n;i++){
            par[a[i]]=a[i];
            s[a[i]].insert(a[i]);
        }
        par[xa]=xa; s[xa].insert(xa);
        auto unite=[&](int x,int y){
            if(par[x]==par[y]) return;
            x=par[x],y=par[y];
            if(s[x].size()>s[y].size()){
                for(auto v:s[y]){
                    s[x].insert(v);
                    par[v]=x;
                }
            }
            else{
                for(auto v:s[x]){
                    s[y].insert(v);
                    par[v]=y;
                }
            }
        };
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                res++;
                unite(a[i],b[i]);
            }
        }
        set<int> ss;
        for(int i=0;i<n;i++){
            if(!ss.count(a[i]) && par[a[i]]==a[i]){
                ss.insert(a[i]);
                if(s[a[i]].size()>1 && !s[a[i]].count(xb)){
                    res++;
                }
            }
        }
        cout<<res<<endl;
        
    }


    
    return 0;
}
