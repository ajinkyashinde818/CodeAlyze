#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<deque>
#include<cstdio>
#include<ctime>
#include<bitset>
#include<vector>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
#define ULL unsigned long long
LL read(){
	LL f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return f*x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
LL dep[MAXN+5];
int ncnt=1,G[MAXN+5][2];
void Insert(char S[]){
	int p=1;
	for(int i=1;S[i];i++){
		if(!G[p][S[i]-'0'])
			G[p][S[i]-'0']=++ncnt,dep[ncnt]=dep[p]-1;
		p=G[p][S[i]-'0'];
	}
	return ;
}
char S[MAXN+5];
int main(){
	int n=read();dep[1]=read();
	for(int i=1;i<=n;i++){
		scanf("%s",S+1);
		Insert(S);
	}
	LL ans=0;
	for(int i=1;i<=ncnt;i++)
		if((!G[i][0]&&G[i][1])||(!G[i][1]&&G[i][0]))
			ans^=dep[i]&-dep[i];
	if(!ans) puts("Bob");
	else puts("Alice");
	return 0;
}
