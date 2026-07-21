//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<iomanip>
#include<cctype>
#include<cstdio>
#include<deque>
#include<utility>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define INF 1000000000
#define ll long long
#define RE register
#define a(i) s[i].A
#define b(i) s[i].B
#define c(i) s[i].C
#define id(i) s[i].id
using namespace std;
char buf[1<<15],*fs,*ft;
inline char getc()
{
    return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline int read()
{
    RE int x=0,f=1;char ch=getc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getc();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getc();}
    return x*f;
}
const int MAXN=110;
int n,top,k;
int a[MAXN];
int main()
{
	//freopen("1.in","r",stdin);
	n=read();k=read();
	if(n>=10)printf("%d\n",k);
	else printf("%d\n",k+100*(10-n));
	return 0;
}
