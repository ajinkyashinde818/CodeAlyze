#include <bits/stdc++.h>
using namespace std;



int main()
{    
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;cin>>n;
    int a[n];
    long long ans=0;
    int neg=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=0){
            neg++;
        }
        a[i]=abs(a[i]);
        ans+=a[i];

    }
    if(neg%2==0){
        cout<<ans;
        return 0;
    }
    sort(a,a+n);
    cout<<ans-2*a[0];

}
