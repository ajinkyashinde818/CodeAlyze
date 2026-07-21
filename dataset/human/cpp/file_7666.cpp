#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long sum=0,ans=2e18;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    long long tmp=0;
    for(int i=0;i<n-1;i++){
        tmp+=2*a[i];
        if(i+1<n)ans=min(ans,abs(sum-tmp));
    }
    cout<<ans<<endl;
    return 0;
}
