#include <bits/stdc++.h> 
using namespace std;
const long INF=1000000000000000;
const long MOD=1000000007;

int main() {
    long N;
    cin>>N;
    vector<long> a(N);
    for(int i=0;i<N;i++)cin>>a.at(i);
    
    vector<long> sum(N,0);
    sum.at(0)=a.at(0);
    for(int i=1;i<N;i++)sum.at(i)=sum.at(i-1)+a.at(i);
    
    long ans=INF;
    
    for(int i=0;i<N-1;i++){
        ans=min(ans,abs(sum.at(N-1)-2*sum.at(i)));
    }
    cout<<ans<<endl;
    
}
