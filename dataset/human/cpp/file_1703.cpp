#include<cstdio>
#include<algorithm>
using namespace std;
int gi(){
	int x=0,w=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if (ch=='-') w=0,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return w?x:-x;
}
const int N = 1005;
int n,m,id[N][N],cnt;
int main(){
	n=gi();
	while (m*(m-1)/2<n) ++m;
	if (m*(m-1)/2!=n) return puts("No"),0;
	for (int i=1;i<=m;++i)
		for (int j=i+1;j<=m;++j)
			id[i][j]=id[j][i]=++cnt;
	printf("Yes\n%d\n",m);
	for (int i=1;i<=m;++i){
		printf("%d ",m-1);
		for (int j=1;j<=m;++j)
			if (i!=j) printf("%d ",id[i][j]);
		puts("");
	}
	return 0;
}
