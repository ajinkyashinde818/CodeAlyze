#include <iostream>
using namespace std;
typedef long long ll;
ll n,C,a[100002],b[100002],c[100002],d[100002],dis[100001],ene[100001],ans;
int main(void){
    cin>>n>>C;
    for(int i=1;i<=n;i++){
        cin>>dis[i]>>ene[i];
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+dis[i-1]-dis[i]+ene[i];
        b[i]=a[i]-dis[i];
    }
    dis[n+1]=C;
    for(int i=n-1;i>=0;i--){
        c[i]=c[i+1]+C-dis[i+2]-C+dis[i+1]+ene[i+1];
        d[i]=c[i]-C+dis[i+1];
        //cout<<c[i]<<endl;
    }
    //for(int i=1;i<=n+1;i++)cout<<a[i-1]<<" "<<b[i-1]<<" "<<c[i-1]<<" "<<d[i-1]<<endl;
    for(int i=1;i<=n;i++){
        a[i]=max(a[i],a[i-1]);
        b[i]=max(b[i],b[i-1]);
        c[n-i]=max(c[n-i],c[n-i+1]);
        d[n-i]=max(d[n-i],d[n-i+1]);
    }
    for(int i=0;i<=n;i++){
        ans=max(ans,a[i]+d[i]);
        ans=max(ans,b[i]+c[i]);
    }
    cout<<ans<<endl;
}
