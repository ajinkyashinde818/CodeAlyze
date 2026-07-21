#include <iostream>
#include <set>
#include <cmath>
using namespace std;
const int N=100000+10;
int n,a[N];
int main(){
    scanf("%d",&n);
    long long ans=0;
    multiset<long long> st1,st2;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans=ans+abs(a[i]);
        if(a[i]<0)st1.insert(a[i]);
        if(a[i]>=0)st2.insert(a[i]);
    }
    if(st1.size()%2==0){
        cout<<ans<<endl;
    }else{
        long long d=1e18;
        if(st1.size()) d=min(d,-(*st1.rbegin()));
        if(st2.size()) d=min(d,*st2.begin());
        ans-=2*d;
        cout<<ans<<endl;
    }
}
