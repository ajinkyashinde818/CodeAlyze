#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <iomanip>
#include <bitset>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define x first
#define y second
#define pi acos(-1.0)
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
//#define dprintf(...)
#define hash _hash
//#define dprintf(...) fprintf(outFile,__VA_ARGS__)

#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ull unsigned long long
#define ll long long
#define N 2000010

template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}

//FILE* outFile;

inline void add(int &a,int b){a+=b;while(a>=mod)a-=mod;}

int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*(ll)a%mod;
        a=(ll)a*a%mod;b>>=1;
    }
    return ans;
}


int main(){
    int j,k,i,T,ca=0,n,K=0,m;
    int r,g,b, ans = 0;
    scanf("%d%d%d%d", &r, &g, &b, &n);
    rep(i, 0, n+1){
        if(i * r > n)break;
        rep(j, 0, n-i+1){
            K = i * r + j * g;
            if(K > n)break;
            if((n - K) % b == 0)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
