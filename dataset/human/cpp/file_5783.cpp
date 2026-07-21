#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll g(ll x){
    if(x==0) return 0;
    return 1LL<<(__builtin_ffs(x)-1);
}

struct Tree{
    bool checked;
    Tree* t0;
    Tree* t1;
    Tree(bool checked):checked(checked),t0(nullptr),t1(nullptr){};
};

void buildTree(Tree* tr,int idx,string& s){
    tr->checked=true;
    if(idx==s.size()) return;
    if(tr->t0==nullptr){
        tr->t0=new Tree(false);
        tr->t1=new Tree(false);
    }
    if(s[idx]=='0') buildTree(tr->t0,idx+1,s);
    if(s[idx]=='1') buildTree(tr->t1,idx+1,s);
    return;
}

void search(Tree* tr,int depth,vector<ll>& res){
    if(!tr->checked){
        res.push_back(depth);
    }
    if(tr->t0!=nullptr) search(tr->t0,depth+1,res);
    if(tr->t1!=nullptr) search(tr->t1,depth+1,res);
}

int main(){
    int n;
    cin>>n;
    ll l;
    cin>>l;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    Tree* root=new Tree(false);
    for(int i=0;i<n;i++) buildTree(root,0,s[i]);
    vector<ll> dep;
    search(root,0,dep);
    ll res=0;
    for(int i=0;i<dep.size();i++){
        cerr<<l-dep[i]+1<<endl;
        res^=g(l-dep[i]+1);
    }
    
    cout<<(res ? "Alice" : "Bob")<<endl;
    
    return 0;
}
