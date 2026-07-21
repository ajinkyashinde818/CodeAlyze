// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int ch[100111][2],tot;bool die[100111];
int n;LL l;
char s[100111];
LL dfs(int x,int d)
{
	if(x==0)return (l-d+1)&-(l-d+1);
	if(die[x])return 0;
	return dfs(ch[x][0],d+1)^dfs(ch[x][1],d+1);
}
int main()
{
	tot=1;
	get2(n,l);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int cur=1;
		for(int j=1;s[j];j++)
		{
			if(!ch[cur][s[j]-'0'])ch[cur][s[j]-'0']=++tot;
			cur=ch[cur][s[j]-'0'];
		}
		die[cur]=1;
	}
	puts(dfs(1,0)?"Alice":"Bob");
	return 0;
}
