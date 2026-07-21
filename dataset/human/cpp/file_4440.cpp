#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
struct node{
	int x,id;
};
node s1[MAXN],s2[MAXN];
int a[MAXN],b[MAXN];
int n,sum,cnt;
map<int,int>fa;
map<int,int>mp;
int getfather(int x){
	if (fa[x]==x) return x;
	fa[x]=getfather(fa[x]);
	return fa[x];
}
bool cmp(node x,node y)
{
	return x.x<y.x;
}
void adit(int x,int y)
{
	x=getfather(x); y=getfather(y); 
	if (x!=y) {
		fa[x]=y; 
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
        s1[i].x=a[i]; s1[n+1].x^=a[i]; 
	}
	a[n+1]=s1[n+1].x;
    for (int i=1;i<=n;i++) {
    	scanf("%d",&b[i]); 
    	s2[i].x=b[i]; s2[n+1].x^=b[i]; 
	}
	b[n+1]=s2[n+1].x;
	s1[n+1].id=n+1; s2[n+1].id=n+1;
	sort(s1+1,s1+n+2,cmp);
	sort(s2+1,s2+n+2,cmp);
	int w=0;
	for (int i=1;i<=n+1;i++) fa[i]=i;
	for (int i=1;i<=n+1;i++)
	 if (s1[i].x!=s2[i].x) {
	 	printf("%d\n",-1); return 0;
	 }
	sum=0;
	for (int i=1;i<=n+1;i++)
	 if (a[i]!=b[i]||i==n+1)  {
	 	if (!mp[a[i]]) mp[a[i]]=++cnt;
	 	if (!mp[b[i]]) mp[b[i]]=++cnt;
	 	if (i<=n) w++;
	 }
	 if (w==0) {
	 	printf("%d\n",0); return 0;
	 }
	for (int i=1;i<=n;i++) adit(mp[a[i]],mp[b[i]]);
	for (int i=1;i<=cnt;i++) if (fa[i]==i) sum++; 
     printf("%d\n",w+sum-1);
}
