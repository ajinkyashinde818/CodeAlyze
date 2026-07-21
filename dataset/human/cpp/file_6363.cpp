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
char in[210000];
int f[210000];
int t[210000];
int main(){
	int a;scanf("%d",&a);
	scanf("%s",in);
	char now='W';
	int cnt=0;
	for(int i=0;i<a*2;i++){
		if(now!=in[i]){
			f[i]=1;
			now=in[i];
			cnt++;
		}
	}
	if(cnt%2)f[a*2]=1;
	//for(int i=0;i<=a*2;i++)printf("%d",f[i]);printf("\n");
	for(int i=0;i<a*2;i++){
		if(f[i]){
			t[i]=1;
			f[i]=0;
		}else{
			if(f[i+1]==0){
				f[i+1]=1;
				t[i]=2;
			}else{
				f[i+1]=0;
				t[i]=2;
			}
		}
	}
	for(int i=0;i<a*2+1;i++){
		if(f[i]){printf("0\n");return 0;}
	}
	long long ret=1;
	int rem=0;
	for(int i=0;i<a*2;i++){
		if(t[i]==1)rem++;
		else{
			ret=ret*rem%mod;
			rem--;
		}
	}
	if(rem!=0)ret=0;
	for(int i=0;i<a;i++)ret=ret*(i+1)%mod;
	printf("%lld\n",ret);
}
