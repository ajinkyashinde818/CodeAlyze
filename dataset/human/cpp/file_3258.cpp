#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,b=0,a[100005],m=1000000001;
long long ans=0;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0) b++;
        ans+=abs(a[i]);
        m=min(m,abs(a[i]));
    }
    if(b%2) ans-=(m*2);
    cout<<ans<<endl;
}
