#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
const int MaxN = 1e5;
LL sum;
int n;
LL a[2 * MaxN + 5];
LL q[2 * MaxN + 5];

int main()
{
	while(~scanf("%d",&n)){
		sum = 0;
	LL ans = 1LL << 60;
	LL fir,sec,num;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		sum += a[i];
	}
	for(int i = 1;i <= n;i++)
		q[i] = q[i-1] + a[i];
	if(n == 2)printf("%lld\n",abs(a[1] - a[2]));
else if(n > 2){
	for(int i = 2;i <= n-1;i++)
	{
		num = abs((sum - q[i]) - q[i]);
		ans = min(ans,num);
	}
	printf("%lld\n",ans);
}
	memset(a,0,sizeof(a));
	memset(q,0,sizeof(q));
}
return 0;
}
