#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000000];
int main(int argc, char const *argv[]) {
   ll n,sum=0,dum=0,mn=1e18;
   cin>>n;
   for(int i=0;i<n;i++){
     cin>>a[i];
     sum+=a[i];
   }
   for(int i=0;i<n-1;i++){
     dum+=a[i];
     sum-=a[i];
     ll k=abs(sum-dum);
     mn=min(mn,k);
   }
   cout<<mn<<endl;

  return 0;
}
