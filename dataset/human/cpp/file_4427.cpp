#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int x,y,ans,top,n;
int a[MAXN],b[MAXN],count1[MAXN],count2[MAXN],fa[MAXN];
map<int,int>mapp;
void push(int x) {if(!mapp.count(x)) mapp[x]=++top;}
int find(int x){if (x==fa[x]) return x; else return fa[x]=find(fa[x]);}
int main() {
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		x^=a[i];
	}
	
	for (int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		y^=b[i];
	}
	bool flag=true;
	for (int i=1;i<=n;++i)
		if (a[i]!=b[i]){
			flag=false;
			break;
		}
	if (flag){printf("0");exit(0);}
	for (int i=1;i<=n;++i) {
		if (a[i]==b[i])continue;
		ans++;push(a[i]);push(b[i]);
		count1[mapp[a[i]]]++;count2[mapp[b[i]]]++;
	}
	push(x);push(y);
	count1[mapp[x]]++;count2[mapp[y]]++;
	for(int i=1;i<=top;i++){
		if (count1[i]==count2[i]) continue;
		printf("-1");
		exit(0);
	}
	for(int i=1;i<=top;i++)fa[i]=i;
	for (int i=1;i<=n;++i) if(a[i]!=b[i]) fa[find(mapp[a[i]])]=find(mapp[b[i]]);
	if(x!=y) fa[find(mapp[x])]=find(mapp[y]);
	 
	for(int i=1;i<=top;i++)
		if(i==find(i)) ans++;
	printf("%d",ans-1);
}
