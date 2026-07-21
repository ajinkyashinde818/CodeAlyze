#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>
#include <assert.h>
#include <functional>
#define  lowbit(x) (x&(-x))
#define  ll long long
#define  ull unsigned long long
#define  max(a,b) (a>b?a:b)
#define  min(a,b) (a>b?b:a)
#define  PI acos(-1.0)
#define  fir first
#define  sec second
#define  SZ(x) (x.size())
#define  inf 0x3f3f3f3f
#define  PB push_back
#define  MP make_pair
#define  all(x) (x).begin(),(x).end()
#define  PII pair<int,int>
#define  E 2.7182818284590452353602874713527
using namespace std;

/**********************************************Head-----Template****************************************/
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

const ll mod = 9901;
ll ksm(ll a,ll b){ll ans=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1) ans=ans*a%mod;a=a*a%mod;}return ans;}
/********************************Head----Template**********************************************/

multiset<int>s;
vector<int>vec;

ll dp[100007][3];

ll a[100007],b[100007];

int main (){
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dp[0][0]=0;
    dp[0][1]=-100000000000;
    for(int i=0;i<n;i++) {
        dp[i+1][0]=max(dp[i][0]+a[i],dp[i][1]-a[i]);
        dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
    }
    cout<<dp[n][0]<<endl;
    //for(int i=0;i<=n+1;i++)
    //cout<<dp[i][1]<<" "<<dp[i][0]<<endl;
    return 0;
}
