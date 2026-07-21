#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


long long dis[100050];
long long nutri[100050];
long long clockw[100050];
long long clock_ret[100050];
long long cclock[100050];
long long cclock_ret[100050];
int main()
{
    long long sum=0;
    long long n,c;
    cin>>n>>c;
    long long ans=0;
    for(int i=1;i<=n;i++){

        scanf("%lld",&dis[i]);
        scanf("%lld",&nutri[i]);
        clockw[i] = nutri[i-1]+nutri[i]-dis[i];
        sum+=nutri[i];
        nutri[i] += nutri[i-1];
        clock_ret[i] = max(clock_ret[i-1],clockw[i]-dis[i]);
    }
    for(int i=n;i>0;i--){
        cclock[i] = sum - nutri[i-1]-(c-dis[i]);
        cclock_ret[i] = max(cclock_ret[i+1],cclock[i]-(c-dis[i]));
    }
    for(int i=1;i<=n;i++){
        ans = max(ans,clockw[i]);
        ans = max(ans,cclock[i]);
        ans = max(ans,clock_ret[i-1]+cclock[i]);
        ans = max(ans,cclock_ret[i+1]+clockw[i]);
    }
    cout<<ans<<endl;
    return 0;
}
