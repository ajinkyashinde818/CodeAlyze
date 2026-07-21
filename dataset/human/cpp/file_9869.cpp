#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
char in[110000];
int cnt[26];
int main(){
	int a;scanf("%d",&a);
	scanf("%s",in);
	for(int i=0;i<a;i++){
		cnt[in[i]-'a']++;
	}
	long long ret=1;
	for(int i=0;i<26;i++){
		ret=(ret*(cnt[i]+1))%mod;
	}
	ret=(ret+mod-1)%mod;printf("%lld\n",ret);
}
