#include<bits/stdc++.h>
using namespace std;
 
using lint=long long;

int main()
{
   cin.tie(0);
   ios::sync_with_stdio(false);

   int N,R; cin>>N>>R;
   int ans;
   if(N>=10){
      ans=R;
   }else{
      ans=R+100*(10-N);
   }
   cout<<ans<<endl;
   return 0;
}
