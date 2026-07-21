#include<bits/stdc++.h>
using namespace std;
long long int n,u,a[5000000],ans,b[5000000],ma=0,mi=1145141919;
vector<int> d;

int  main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0)u++;
    }

    for(int i=0;i<n;i++){
       mi=min(abs(a[i]),abs(mi));
    }

    for(int i=0;i<n;i++){
       ans+=abs(a[i]);
    }







    if(u%2==0)cout<<ans<<endl;
    else cout<<ans-(mi*2)<<endl;

}
