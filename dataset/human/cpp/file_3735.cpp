#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,A[100010];

int main(){
    cin>>N;
    ll cnt=0,sum=0,min=1LL<<60;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<0){
            cnt++;
            A[i]*=-1;
        }
        if(min>A[i])min=A[i];
        sum+=A[i];
    }
    if(cnt%2!=0){
        sum-=min*2;
    }
    cout<<sum<<endl;
    return 0;
}
