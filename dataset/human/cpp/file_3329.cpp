#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin>>n;
    int count=0;
    long long ans=0;
    long long mn=1e9;
    for(int i=0;i<n;i++)
    {long long x;
    cin>>x;

    if(x<0)
        count++;
    ans+=abs(x);
    mn=min(mn,abs(x));
    //cout<<ans<<endl;
    }
    if(count%2==0)
        cout<<ans;
    else
        cout<<ans-(2*mn);
 //   cout<<mn;


    return 0;

}
