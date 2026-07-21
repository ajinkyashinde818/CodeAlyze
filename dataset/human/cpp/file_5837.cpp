#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
const double PI=3.14159265359;

class SegmentTreeMax{
    public:
    int n;
    vector<long long> vect;
    SegmentTreeMax(int _n):n(_n){
        vect.resize(2*n);
        fill(vect.begin(), vect.end(), -MOD);
    }
    void modify(int p, long long value){
        for(vect[p+=n]=value; p>1; p>>=1){
            vect[p>>1]=max(vect[p],vect[p^1]);
        }
    }
    long long query(int l, int r){
        long long res=-MOD;
        for(l+=n, r+=n; l<r; l>>=1, r>>=1){
            if(l&1) res=max(res,vect[l++]);
            if(r&1) res=max(res,vect[--r]);
        }
        return res;
    }
    
};




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long c;
    cin>>n>>c;
    vector<long long> x(n), v(n), cs1(n), cs2(n);
    
    
    for(int i=0; i<n; i++){
        cin>>x[i]>>v[i];
    }
    
    SegmentTreeMax st1(n), st2(n);
    
    long long ans=0;
    //long long val1=0, val2=0, ans=0;
    for(int i=0; i<n; i++){
        if(!i){
            cs1[0]=v[0];
            cs2[0]=v[n-1];
        }
        else{
            cs1[i]=cs1[i-1]+v[i];
            cs2[i]=cs2[i-1]+v[n-1-i];
        }
        //cout<<cs1[i]<<endl;
        st1.modify(i,cs1[i]-2*x[i]);
        st2.modify(i, cs2[i]-2*(c-x[n-1-i]));
        ans=max(max(ans, cs1[i]-x[i]), cs2[i]-c+x[n-1-i]);
    }
    
    for(int i=0; i<n; i++){
        ans=max(ans, cs1[i]-x[i]+ st2.query(0,n-1-i));
        ans=max(ans, cs2[i]-c+x[n-1-i]+ st1.query(0,n-1-i));
    }
    
    cout<<ans;
    
    
    return 0;
    
    
}
