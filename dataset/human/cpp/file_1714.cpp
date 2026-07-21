#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=100010;
vector<int> s[N];
int main()
{
	int n;
	scanf("%d",&n);
	int k=-1;
	for(int i=1;i<=10000;i++)
		if(i*(i-1)/2==n)
		{
			k=i;
			break;
		}
	if(k==-1)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	printf("%d\n",k);
	int t=0;
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
		{
			s[i].push_back(++t);
			s[j].push_back(t);
		}
	for(int i=1;i<=k;i++)
	{
		printf("%d ",k-1);
		for(int j=0;j<k-1;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}
	return 0;
}
