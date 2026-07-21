#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

ll n,c,x[100100]={0},v[100100]={0};
ll res=0;
ll sx[100100]={0},sv[100100]={0},a[100100]={0},b[100100]={0},rx[100100]={0};


signed main(){
    cin>>n>>c;
    for(int i=0;i<n;++i){
        cin>>x[i]>>v[i];
        sv[i+1]=sv[i]+v[i];
        rx[i]=c-x[i];
    }
    
    
    a[n-1]=max(0LL,v[n-1]-rx[n-1]),b[n-1]=max(0LL,v[n-1]-2*rx[n-1]);
    for(int i=n-2;i>=0;--i){
        a[i]=max(a[i+1],sv[n]-sv[i]-rx[i]);
        b[i]=max(b[i+1],sv[n]-sv[i]-2*rx[i]);
    }

    for(int i=0;i<=n;++i){
        ll t=sv[i];
        if(i==0){
            t+=a[0];
            res=max(res,t);
        }
        else{
            t-=x[i-1];
            ll s=t;
            int k=lower_bound(rx,rx+n,x[i-1],greater<ll>())-rx;
            if(k<n){
                if(i<=k)t=max(t,s+b[k]);
                else t=max(t,s+b[i]);
            }
            if(i<n)t=max(t,s+a[i]-x[i-1]);
            res=max(res,t);
        }
        //cout<<a[i]<<" "<<b[i]<<" "<<rx[i]<<endl;
    }

    cout<<res<<endl;



    

    return 0;
}
