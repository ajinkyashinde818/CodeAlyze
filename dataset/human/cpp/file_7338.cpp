#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;

int main(){
   int n;
   cin>>n;
   vector<long long> a(n+2);
   for(int i=0;i<n;i++)cin>>a[i];
   vector<long long>sum(n+2);
   sum[0]=a[0];
   for(int i=1;i<n;i++){
      sum[i]=sum[i-1]+a[i];
   }
   long long ans=1000000000000000000;
   for(int i=0;i<n-1;i++){
      ans=min(ans,abs(sum[i]-(sum[n-1]-sum[i])));
   }
   cout<<ans<<endl;
}
