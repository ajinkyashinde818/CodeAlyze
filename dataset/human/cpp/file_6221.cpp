#include <bits/stdc++.h> 
using namespace std;
long long a[100005],cnt[100005],s1[100005],s2[100005],s=0,n,m,i,j;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=n;i++){
		cin>>a[i]>>cnt[i];
		cnt[i]+=cnt[i-1];
	}
	for (i=1;i<=n;i++){
		s=max(s,cnt[i]-a[i]);
		s1[i]=cnt[i]-a[i]*2;
	}
	for (i=1;i<=n;i++){
		s=max(s,cnt[n]-cnt[i-1]-m+a[i]);
		s2[i]=cnt[n]-cnt[i-1]-m*2+a[i]*2;
	}
	for (i=1;i<=n;i++) s1[i]=max(s1[i],s1[i-1]);
	for (i=n;i>=1;i--) s2[i]=max(s2[i],s2[i+1]);
	for (i=1;i<=n;i++) s=max(s,cnt[i]-a[i]+s2[i+1]);
	for (i=1;i<=n;i++) s=max(s,cnt[n]-cnt[i-1]-m+a[i]+s1[i-1]);
	cout<<s;
	return 0;
}
