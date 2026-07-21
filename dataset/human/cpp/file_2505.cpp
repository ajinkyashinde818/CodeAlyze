#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005],minn=1000000001,ans;
bool zero,minu;

long long m(long long x,long long y){
	return x<y?x:y;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]==0)
			zero=true;
		if(a[i]<0){
			minu=!minu;
			a[i]=-a[i];
		}
		minn=m(minn,a[i]);
		ans+=a[i];
	}
//	cout<<zero<<' '<<minu<<' '<<ans<<' '<<minn<<endl;
	if(!zero && minu)
		ans-=2*minn;
	printf("%lld\n",ans);
}
