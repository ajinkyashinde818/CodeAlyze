#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int A[100010],B[100010],u[200010],U;
std::vector<int>a,b;
int fa[200010];
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),XOR=0,xorb=0;
	for(int i=1;i<=n;++i)A[i]=gi(),XOR^=A[i],a.push_back(A[i]),u[++U]=A[i];
	for(int i=1;i<=n;++i)B[i]=gi(),xorb^=B[i],b.push_back(B[i]),u[++U]=B[i];
	u[++U]=XOR;std::sort(u+1,u+U+1);U=std::unique(u+1,u+U+1)-u-1;
	for(int i=1;i<=n;++i)A[i]=std::lower_bound(u+1,u+U+1,A[i])-u;
	for(int i=1;i<=n;++i)B[i]=std::lower_bound(u+1,u+U+1,B[i])-u;
	a.push_back(XOR),b.push_back(xorb);
	std::sort(a.begin(),a.end());
	std::sort(b.begin(),b.end());
	if(a!=b)return puts("-1"),0;
	int ans=-1;
	for(int i=1;i<=U;++i)fa[i]=i;
	for(int i=1;i<=n;++i)if(A[i]!=B[i])++ans,fa[hd(A[i])]=hd(B[i]);
	if(ans==-1)return puts("0"),0;
	for(int i=1;i<=n;++i)
		if(A[i]!=B[i]){
			if(hd(A[i]))fa[hd(A[i])]=0,++ans;
			if(hd(B[i]))fa[hd(B[i])]=0,++ans;
		}
	XOR=std::lower_bound(u+1,u+U+1,XOR)-u;
	if(fa[XOR])++ans;
	printf("%d\n",ans);
	return 0;
}
