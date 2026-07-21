#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long lll;
const int MAXN=100000+3;
lll n;
lll a[MAXN];
lll b[MAXN];
lll cnt;
lll ans;
int main(){
	scanf("%lld",&n);
	for(lll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<0){
			cnt++;
		}
		if(a[i]<0){
			b[i]=a[i]-a[i]*2;
		}
		else{
			b[i]=a[i];
		}
		ans+=b[i];
	}
	sort(b+1,b+n+1);
	if(cnt%2==1){
		ans-=b[1]*2;
	}
	printf("%lld\n",ans);
	return 0;
}
