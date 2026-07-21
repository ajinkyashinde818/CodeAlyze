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
int x[110000];
long long p[110000];
long long val[110000];
int main(){
	int a;scanf("%d",&a);
	long long b;scanf("%lld",&b);
	for(int i=0;i<a;i++){
		scanf("%lld%d",p+i+1,x+i);
	}
	p[a+1]=b;
	long long ret=0;
	for(int f=0;f<2;f++){
		set<pair<long long,int> >S;
		long long cur=0;
		S.insert(make_pair(0LL,a));
		for(int i=a-1;i>=0;i--){
			cur+=x[i];
			cur-=p[i+2]-p[i+1];
			val[i]=cur;
			S.insert(make_pair(cur,i));
		}
		cur=0;
		for(int i=0;i<a;i++){
			ret=max(ret,(S.rbegin()->first)+cur);
			cur+=x[i];
			cur-=(p[i+1]-p[i])*2;
			S.erase(make_pair(val[i],i));
		}
		reverse(p,p+a+2);
		reverse(x,x+a);
		for(int i=0;i<a+2;i++)p[i]=b-p[i];
	}
	printf("%lld\n",ret);
}
