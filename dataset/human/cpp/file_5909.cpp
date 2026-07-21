#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    ll n,c;
    cin>>n>>c;
    vector<ll> x,v;
    for(int i=0;i<n;i++){
        ll x_,v_;
        cin>>x_>>v_;
        x.push_back(x_);
        v.push_back(v_);
    }
    vector<ll> r,l;
    for(int i=0;i<n;i++){
        static ll cc=0;
        cc+=v[i];
        if(i==0){
            cc-=x[i];
        }else{
            cc-=x[i]-x[i-1];
        }
        r.push_back(cc);
    }
    for(int i=0;i<n;i++){
        static ll cc=0;
        cc+=v[n-1-i];
        if(i==0){
            cc-=c-x[n-1-i];
        }else{
            cc-=x[n-i]-x[n-1-i];
        }
        l.push_back(cc);
    }
    vector<ll> rmax;
    vector<ll> lmax;
    {
        ll max=0;
        for(auto rr:r){
            if(rr>max) max=rr;
            rmax.push_back(max);
        }
    }
    {
        ll max=0;
        for(auto ll:l){
            if(ll>max) max=ll;
            lmax.push_back(max);
        }
    }
    vector<ll> ans;
    ans.push_back(lmax.back());
    ans.push_back(rmax.back());
    for(int i=0;i<n-1;i++){
        ans.push_back(r[i]-x[i]+lmax[n-2-i]);
    }
    for(int i=0;i<n-1;i++){
        ans.push_back(l[i]-(c-x[n-1-i])+rmax[n-2-i]);
    }
    cout<<*max_element(ans.begin(),ans.end())<<endl;

    return 0;
}
