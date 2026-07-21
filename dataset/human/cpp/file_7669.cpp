#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long a[MAXN];
long long b[MAXN];
long long ans=0;
int main(){
    int n;
    cin >>n;    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        ans+=a[i];
    }
    long long cmin=INT_MAX;
    for(int i=1;i<n;i++)if(cmin>abs(2*b[i]-ans))cmin=abs(2*b[i]-ans);
    cout<<cmin<<endl;
    return 0;
}
