#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1000+19;

struct Circle{
	int x,y,r;
} C[N];
db dis[N];
int vis[N];
int n;

db calc(int i,int j){
	db dis=sqrt(1.0*(C[i].x-C[j].x)*(C[i].x-C[j].x)+1.0*(C[i].y-C[j].y)*(C[i].y-C[j].y));
	return max(dis-C[i].r-C[j].r,0.0);
}

int main(){
	C[1]=(Circle){IN(),IN(),0};
	C[2]=(Circle){IN(),IN(),0};
	n=IN();
	For(i,1,n+1) C[i+2]=(Circle){IN(),IN(),IN()};
	For(i,0,n+3) dis[i]=1e60;
	dis[1]=0;
	For(i,1,n+3){
		int x=0;
		For(j,1,n+3){
			if (!vis[j]&&dis[j]<dis[x]) x=j;
		}
		vis[x]=1;
		For(j,1,n+3){
			if (!vis[j]&&dis[x]+calc(x,j)<dis[j]) dis[j]=dis[x]+calc(x,j);
		}
	}
	printf("%.20lf\n",dis[2]);
}
