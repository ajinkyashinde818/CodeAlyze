#include<bits/stdc++.h>
using namespace std;
int a[3000100],b[3000100],fa[3000100],js[3000100];
map<int,int> mp;
int getf(int s){if (fa[s]==s) return s;return fa[s]=getf(fa[s]);}
int main()
{
	int n;scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);mp[a[i]]++;
		a[n+1]^=a[i];
	}
	mp[a[n+1]]++;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);mp[b[i]]--;
		b[n+1]^=b[i];
	}
	mp[b[n+1]]--;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) if (it->second!=0) {cout<<-1<<endl;return 0;}
	int ans=0;
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) ans++;
	if (ans==0) {cout<<ans<<endl;return 0;}
	mp.clear();for (int i=1;i<=n+1;i++) if ((a[i]!=b[i])||(i==n+1)) mp[a[i]]=mp[b[i]]=0;
	int tp=0;for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++tp;
	for (int i=1;i<=tp;i++) fa[i]=i;
	for (int i=1;i<=n+1;i++) if (a[i]!=b[i]) fa[getf(mp[a[i]])]=getf(mp[b[i]]);
	for (int i=1;i<=tp;i++) ans+=(getf(i)==i);
	cout<<ans-1<<endl;
}
