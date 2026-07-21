#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1010;
bool w[N];
double dis[N];
int a[N],b[N],c[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline double D(int x,int y) {
    return max(0.0,sqrt(1LL*(a[x]-a[y])*(a[x]-a[y])+1LL*(b[x]-b[y])*(b[x]-b[y]))-c[x]-c[y]);
}
int main() {
    int n;
    cin>>a[1]>>b[1]>>a[2]>>b[2]>>n,n+=2;
    for(int i=3;i<=n;i++) a[i]=gi(),b[i]=gi(),c[i]=gi();
    for(int i=2;i<=n;i++) dis[i]=1e100;
    dis[0]=1e100;
    while(1) {
	int x=0;
	for(int i=1;i<=n;i++)
	    if(!w[i]&&dis[i]<dis[x]) x=i;
	if(x==2) return printf("%.10f",dis[x]),0;
	w[x]=1;
	for(int i=1;i<=n;i++)
	    if(!w[i]) dis[i]=min(dis[i],dis[x]+D(x,i));
    }
    return 0;
}
