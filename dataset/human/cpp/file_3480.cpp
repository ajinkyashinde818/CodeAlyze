#include<iostream>
#include<cmath>
using namespace std;
int n,a[100005],cnt,f=1e9;
long long ans;
main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(f>abs(a[i]))f=abs(a[i]);
        if(a[i]<0)cnt++;
        ans+=abs(a[i]);
    }
    cout<<(cnt%2?ans-f*2:ans)<<endl;
}
