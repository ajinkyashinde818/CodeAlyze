#include<bits/stdc++.h>
using namespace std;
long long L;
int n,sz;
int ch[500005][2];
int dep[500005];
int ed[500005];
int a[100005];
char s[100005];
void insert(){
	int len=strlen(s+1);
	int x=0;
	for (int i=1;i<=len;i++){
		int t=s[i]-'0';
		if (!ch[x][t]){
			ch[x][t]=++sz;
			dep[ch[x][t]]=i;
		}
		x=ch[x][t];
	}
	ed[x]=1;
}
int work(){
	for (int i=0;i<=sz;i++)
		for (int j=0;j<2;j++)
			if (!ch[i][j]&&!ed[i])
				a[dep[i]+1]++;
}
int main(){
	scanf("%d%lld",&n,&L);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert();
	}
	long long sum2=0;
	work();
	for (int i=1;i<=100002;i++)
		if (a[i]&1){
			long long tmp=(L-i+1);
			sum2^=tmp&(-tmp);
		}
	puts(sum2?"Alice":"Bob");
}
