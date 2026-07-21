#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
long long pos=0,n,ans=0,tot=0,cnt=0;
long long a[200005],b[200005];
long long fa[200005];
map<long long,long long> mp;
map<long long,long long> mmp;
long long find(long long k) {
	if(fa[k]==k)return k;
	return fa[k]=find(fa[k]);
	}
void merge(long long x,long long y) {
	fa[find(x)]=find(y);
	}
int main() {
//	freopen("duliu.in","r",stdin);
//	freopen("duliu.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		pos^=a[i];
		}
	a[n+1]=pos;
	pos=0;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&b[i]);
		mp[b[i]]--;
		pos^=b[i];
		}
	for(int i=1; i<=n+1; i++) {
		mp[a[i]]++;
		}
	bool flag1=true;
	for(int i=1; i<=n; i++) {
		if(mp[b[i]]<0) {
			flag1=false;
			break;
			}
		}
	if(!flag1) {
		cout<<-1;
		return 0;
		}
	b[n+1]=pos;
	for(int i=1; i<=n+1; i++)
		if(a[i]!=b[i]) {
			ans++;
			if(!mmp.count(a[i])) {
				mmp[a[i]]=++cnt;
				fa[cnt]=cnt;
				}
			}
	//cout<<ans<<endl;
	for(int i=1; i<=n; i++)
		if(a[i]!=b[i])
			merge(mmp[a[i]],mmp[b[i]]);
	for(int i=1; i<=n; i++)
		if(fa[i]==i)ans++;
	//cout<<ans<<endl;
	if(a[n+1]!=b[n+1])ans-=2;
	else if(mmp.count(a[n+1]))ans-=1;
	cout<<ans<<endl;
	}
// 0 1 2 3(0)
// 3 2 1 0

// 1 2 3 4 9(13)
// 13 1 2 3 4
