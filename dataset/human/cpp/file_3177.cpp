#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100100];
int main(){
	int n;
	scanf("%d",&n);
	int mi=0x3f3f3f3f;
	int cnt=0;
	ll su=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		su+=1ll*abs(a[i]);
		mi=min(mi,abs(a[i]));
		if(a[i]<0){
			cnt++;
		}
	}
	if(cnt&1){
		su-=mi*2;
	}
	printf("%lld\n",su);
	return 0;
}
