#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
   int r,g,b,n;
   cin >>r>>g >>b >> n;
   int ans=0;
   for(int i=0;i<=3000;i++){
    for(int j=0;j<=3000;j++){
        if((n-r*i-g*j)<0)continue;
        if((n-r*i-g*j)%b==0)ans++;
    }
   }
   cout << ans<<endl;
    return 0;
}
