#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long sum=0;
    int mi=1000000010,minus=0,count0=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a==0)count0++;
        if(a<0)minus++;
        mi=min(mi,abs(a));
        sum+=abs(a);
    }
    if(count0||minus%2==0)cout<<sum<<endl;
    else cout<<sum-2*mi<<endl;
}
