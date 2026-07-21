#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
char s[6666666];
int tot,now,n,son[6666666][2],m,d[6666666];
LL l,ans;
void add(){
	now=0;
	FOR(i,0,m-1){
		if (!son[now][s[i]-'0']) son[now][s[i]-'0']=++tot,d[tot]=d[now]+1;
		now=son[now][s[i]-'0'];
	}
}
LL cal(LL x){
	if (x==0) return 0ll;
	LL t=1;
	while (x%2==0) t<<=1,x/=2;
	return t;
}
int main(){
	cin>>n>>l;
	FOR(i,1,n){
		scanf("%s",s);
		m=strlen(s);
		add();
	}
	FOR(i,0,tot)
		if ((son[i][0]!=0) ^ (son[i][1]!=0)) ans^=cal(l-d[i]);
	if (ans) puts("Alice"); else puts("Bob");
	return 0;
}
