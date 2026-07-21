// #pragma GCC target("avx2")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
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
#include<numeric>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
long long Comb(int a,int b){
 	if(a<b||b<0)return 0;
 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
void init_C(int n){
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<n;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<n;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
long long pw(long long a,long long b){
	if(a<0LL)return 0;
	if(b<0LL)return 0;
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
// ここから編集しろ
char in[110000];
struct wolf{
	int t;
	int ch[2];
	wolf(){t=0;ch[0]=ch[1]=-1;}
};
wolf pool[110000];
long long ret;
int ind=1;
void dfs(int a,long long b){
	if(pool[a].t){
		return;
	}
	if(pool[a].ch[0]==-1){
		long long tmp=1;
		long long v=b;
		while(v%2==0){
			v/=2;tmp*=2;
		}
		ret^=tmp;
	}else dfs(pool[a].ch[0],b-1);
	if(pool[a].ch[1]==-1){
		long long tmp=1;
		long long v=b;
		while(v%2==0){
			v/=2;tmp*=2;
		}
		ret^=tmp;
	}else dfs(pool[a].ch[1],b-1);
	
}
int main(){
	int a;
	long long b;
	scanf("%d%lld",&a,&b);

	for(int i=0;i<a;i++){
		scanf("%s",in);
		int n=strlen(in);
		int at=0;
		for(int j=0;j<n;j++){
			if(in[j]=='0'){
				if(pool[at].ch[0]!=-1){
					at=pool[at].ch[0];
				}else{
					pool[at].ch[0]=ind;
					at=ind;
					ind++;
				}
			}else{
				if(pool[at].ch[1]!=-1){
					at=pool[at].ch[1];
				}else{
					pool[at].ch[1]=ind;
					at=ind;
					ind++;
				}
			}
		}
		pool[at].t=1;
	}

	dfs(0,b);
	if(ret)printf("Alice\n");else printf("Bob\n");
}
