#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200005],c[200005],b[200005],left,right,same;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	for(int i=1;i<=n;++i) b[i]=c[n-i+1];
	for(int i=1;i<=n;++i) if(a[i]==b[i]) {
		if(!left) left=i;right=i;same=a[i];
	}
	if(left) {
		for(int i=n;i>=right;--i) {
			if(a[i]==same||b[i]==same) break;
			swap(b[i],b[left]);++left;if(left>right) break;
		}
		if(left<=right)
		for(int i=1;i<=left;++i) {
			if(a[i]==same||b[i]==same) break;
			swap(b[i],b[right]);--right;if(left>right) break;
		}
	}
	if(left>right||!left) {printf("Yes\n");for(int i=1;i<=n;++i) printf("%d ",b[i]);}
	else printf("No");
	return 0;
}
