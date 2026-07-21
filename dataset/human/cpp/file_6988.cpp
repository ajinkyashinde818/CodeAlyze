#include<bits/stdc++.h>
using namespace std;

inline void azhe(){
    cout<<"No\n";
    exit(0);
}

inline bool get_diff(const int &x,set<pair<int,int>> &t,pair<int,int> &p){
    if(t.empty())return false;
    if(t.rbegin()->second==x){
        if(t.size()<2)return false;
        t.erase(p=*----t.end());
        return true;
    }
    t.erase(p=*--t.end());
    return true;
}

inline void solve(const vector<int> &a,vector<int> &b){
    const int n=a.size();
    map<int,int> occa,occb;
    for(int i=0;i<n;i++){
        occa[a[i]]++;
        occb[b[i]]++;
    }
    set<pair<int,int>> num;
    for(pair<const int,int> &p:occb){
        num.insert(make_pair(occa[p.first]+p.second,p.first));
        if(occa[p.first]+p.second>n)azhe();
    }
    for(int i=0;i<n;i++){cerr<<i<<endl;
        pair<int,int> p;
        if(!get_diff(a[i],num,p))azhe();
        b[i]=p.second;
        occa[a[i]]--;
        occb[p.second]--;
        p.first--;
        if(occb[p.second]==0){
            occb.erase(p.second);
        }else{
            num.insert(p);
        }
        if(occb.find(a[i])!=occb.end()){
            num.erase(make_pair(occa[a[i]]+1+occb[a[i]],a[i]));
            num.insert(make_pair(occa[a[i]]+occb[a[i]],a[i]));
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int &x:a)cin>>x;
    for(int &x:b)cin>>x;
    solve(a,b);
    cout<<"Yes\n";
    for(int &x:b)cout<<x<<' ';
    cout<<'\n';

    return 0;
}
