#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    long a[n],b[n],ans=0,tmp=1;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]>=0)b[i]=1;
        else b[i]=-1;
        
        a[i]=abs(a[i]);
        tmp*=b[i];
    }
    sort(a,a+n);
    if(tmp==-1)a[0]*=-1;
    for(int i=0;i<n;++i){
        ans+=a[i];
    }
   cout<<ans<<endl;
	return 0;
}
