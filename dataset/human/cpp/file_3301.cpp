#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n;
int a[maxn];
int flag;
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		ans+=abs(a[i]);
		if(a[i]<0) flag^=1;	
	}
	for(int i=1;i<=n;i++) a[i]=abs(a[i]);
	sort(a+1,a+1+n);
	if(!flag) printf("%lld\n",ans);
	else printf("%lld\n",ans-2*abs(a[1]));
	return 0;
}
