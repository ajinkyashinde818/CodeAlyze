#include <bits/stdc++.h>
using namespace std;

int main(){
 
    int N;
    cin>>N;
    vector<long long int> sum(N+1);
    for(int i=0;i<N;i++){
        long long int a;cin>>a;
        sum[i+1]=sum[i]+a;
    }
    long long int ans;
    for(int i=0;i<N-1;i++){
        if(i==0) ans=abs(sum[N]-2*sum[i+1]);
        else ans=min(ans,abs(sum[N]-2*sum[i+1]));
    }
    cout<<ans<<endl;
}
