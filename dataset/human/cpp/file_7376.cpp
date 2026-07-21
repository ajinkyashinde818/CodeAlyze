#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
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
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int p[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	long long cur=0;
	long long sum=0;
	for(int i=0;i<a;i++)sum+=p[i];
	long long ret=inf;
	for(int i=0;i<a-1;i++){
		cur+=p[i];
		ret=min(ret,ABS(sum-cur-cur));
	}
	printf("%lld\n",ret);
}
