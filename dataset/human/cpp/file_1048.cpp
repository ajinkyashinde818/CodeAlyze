#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;


int main(){
    ll r,g,b,n;
    cin>>r>>g>>b>>n;
    ll ans=0;
    for(ll i=0;i*r<=n;i++){
        for(ll t=0;i*r+t*g<=n;t++){
            if((n-t*g-i*r)%b==0){ans++;}
        }
    }
    cout<<ans<<endl;

    return 0;
}
