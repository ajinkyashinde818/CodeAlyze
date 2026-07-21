#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*
ll t;
cin>>t;

while(t--)
{
*/


ll n,r;
cin>>n>>r;

if(n>=10)
cout<<r<<endl;
else
{
  cout<<r+(100*(10-n))<<endl;

}

return 0;
}
