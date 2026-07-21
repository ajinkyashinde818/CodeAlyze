#include <iostream>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>

#define D(x) cout<< #x <<" = "<<x<<"\n"
#define IL(a,n) for (int i=a; i<n; i++)
#define II() ( { int a ; read(a) ; a; } )
#define LL() ( { Long a ; read(a) ; a; } )
#define DD() ({double a; scanf("%lf", &a); a;})

using namespace std;

//Fast Reader
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; 
    x*=sgn; return ~c;
}

typedef long long Long;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF=2e9;
const int MX=100005;
const int MOD=1000000007;
const double PI=acos(-1.0);

/*_______________________________________________*/
int arr[MX],n;
Long dp[2][MX];

Long solve(bool flag,int pos)
{
	if(pos == n-1)
		if(flag) return -1*arr[pos];
		else return arr[pos];
	if(dp[flag][pos] != -1) return dp[flag][pos];
	Long res = 0;
	if(flag)
		res = max(-1*arr[pos]+solve(false,pos+1),arr[pos] + solve(true,pos+1));
	else
		res = max(arr[pos]+solve(false,pos+1),-1*arr[pos]+solve(true,pos+1));
	return dp[flag][pos] = res;
}

int main()
{

	n = II();
	for(int i = 0; i<n; i++) arr[i] = II();

	memset(dp,-1,sizeof(dp));
	printf("%lld\n",solve(false,0));

	return 0;
}
