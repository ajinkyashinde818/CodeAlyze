#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    long long n,ans=0;
    cin>>n;
    long long a[n];
    map <long long,long long> m1;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    //for(long long i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
    //for(long long i=0;i<n;i++) ans+=a[i];
    sort(a,a+n);
    for(long long i=0;i<n-1;i++){
        if(a[i]+a[i+1]<0){
            a[i]=-a[i];
            a[i+1]=-a[i+1];
        }
    }
    //for(long long i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
    for(long long i=0;i<n;i++) ans+=a[i];
    cout<<ans<<"\n";
    
    return 0;
}
