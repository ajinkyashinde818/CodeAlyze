#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int N;  cin>>N;
    ll ans=0;
    vector<ll> A(N,0);
    bool can=false;
    int count=0,minimum=100001;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==0)true;
        if(A[i]<0)count++;
        A[i]=abs(A[i]);
        ans+=abs(A[i]);
    }
    sort(A.begin(),A.end());
    if(can||count%2==0){
        cout<<ans;
    }
    else{
        cout<<ans-(2*A[0]);
    }
    return 0;
}
