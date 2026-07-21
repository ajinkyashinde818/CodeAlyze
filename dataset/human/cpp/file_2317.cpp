#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
   int n;cin>>n;
   ll a[n];
   int co=0;
   ll sum=0;
   ll mint=10010010011;
   for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=abs(a[i]);
    if(a[i]<0)co++;
    mint=min(abs(mint),abs(a[i]));
   }
   ll ans;
   if(co%2==0){
    ans=sum;
   }
   else {
    ans=sum-abs(mint)*2;
   }
   cout << ans << endl;
    return 0;
}
