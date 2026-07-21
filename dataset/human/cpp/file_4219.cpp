#include"bits/stdc++.h"
using namespace std;
using ll=long long;
using ull=unsigned long long;
constexpr auto inf=static_cast<ll>(1e18);
template<typename T=ll>inline T in(){T ret;cin>>ret;return ret;}
template<typename T=ll>inline auto vec2(size_t h,size_t w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
inline void setp(int n){cout<<fixed<<setprecision(n);}
inline void delnl(){cin.ignore(numeric_limits<streamsize>::max(),'\n');}

int main()
{
    ll t=in();
    if(t==0){
        cout<<0<<endl;
    }else{
        ll ans=t/3+(t%3==0?2:t%3);
        ll num_of=(t-1)/3;
        while(num_of>=5){
            num_of=(num_of-2)/3;
            ans-=num_of*2;
        }
        cout<<ans<<endl;
    }
}
