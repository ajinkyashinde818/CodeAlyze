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
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
long long x[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%lld",x+i);
	int cn=0;
	long long ret=0;
	for(int i=0;i<a;i++){
		if(x[i]<0)cn++;
		x[i]=ABS(x[i]);
		ret+=x[i];
	}
	std::sort(x,x+a);
	if(cn%2)ret-=x[0]*2;
	printf("%lld\n",ret);
}
