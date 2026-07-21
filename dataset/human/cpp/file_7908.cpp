#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    long long sum=0;
    int a[200000];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    long long ans=10000000000000000;
    long long sum2=0;
    for(int i=0;i<n-1;i++){
        sum-=a[i];
        sum2+=a[i];
        //cout<<sum2<<" "<<sum<<endl;
        ans=min(ans,abs(sum2-sum));
    }
    cout<<ans<<endl;
    return 0;
}
