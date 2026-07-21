#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    ll n,c;
    cin>>n>>c;
    vector<ll> x(n);
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>x[i]>>v[i];
    auto func=[&](){
        
    ll res=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        res=max(res,sum-x[i]);
    }

    stack<pair<ll,ll>> rev;
    rev.push({0LL,n});
    sum=0;
    for(int i=n-1;i>=0;i--){
        auto ret=rev.top();
        sum+=v[i];
        if(ret.first<sum-(c-x[i])){
            rev.push({sum-(c-x[i]),i});
        }
    }
    
    sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        while(rev.top().second<=i){
            rev.pop();
        }
        
        res=max(res,sum-x[i]*2+rev.top().first);
    }
    
    return res;
    };
    ll res=func();
    for(int i=0;i<n;i++){
        x[i]=c-x[i];
    }
    reverse(x.begin(),x.end());
    reverse(v.begin(),v.end());
    res=max(res,func());
    cout<<res<<endl;

    return 0;
}
