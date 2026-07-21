#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n;
ll arr[100005];
int main()
{
    cin>>n;

    for(ll i=0;i<n;i++)cin>>arr[i];

    ll ne = 0;
    ll po = 0;
    ll s = 0;
    ll mi = INT_MAX;
    for(ll i=0;i<n;i++){
        if(arr[i]<0){
            ne+=1;
        }
        else{
            po+=1;
        }
        s+=abs(arr[i]);
        mi = min(mi,abs(arr[i]));
    }

    if(ne%2==0){
        cout<<s<<endl;
    }
    else{
            //cout<<mi<<endl;
        cout<<(s-2*mi)<<endl;
    }




}
