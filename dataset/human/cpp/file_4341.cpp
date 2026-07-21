#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);
const int N=1e5+500;
typedef pair<int,int>P;
#define fi first
#define se second
#define mk make_pair
int n,res;
int a[N],b[N],c[N],d[N],vis[N],cnt[N];
int Xor=0;
std::map<int,int>Mp;
typedef std::map<int,int>::iterator Mpit;
std::vector<P>G[N];
/*==================Define Area================*/
void Bo() {
	freopen("duliu.in","r",stdin);
	freopen("duliu.out","w",stdout);
}

void Dfs(int o) {
	for(int i=0;i<(int)G[o].size();i++) {
		int to=G[o][i].fi;
		if(G[o][i].se) continue ;
		// printf("%d->%d\n",o,to);
		G[o][i].se=1;
		vis[to]++;
		res++;
		Dfs(to);
	}
}

int main() {
	// Bo();
	read(n);
	for(int i=1;i<=n;i++) {
		read(a[i]);c[i]=a[i];Xor^=a[i];
	}
	c[n+1]=Xor;
	sort(c+1,c+2+n);
	for(int i=1;i<=n;i++) {
		read(b[i]);d[i]=b[i];
	}
	sort(d+1,d+1+n);
	int now=1;
	for(int i=1;i<=n+1;i++) {
		if(now<=n&&d[now]==c[i]) now++;
	}
	if(now!=n+1) return puts("-1"),0;
	for(int i=1;i<=n;i++) {
		Mp[a[i]]=1;Mp[b[i]]=1;
	}
	Mp[Xor]=1;
	int tot=0;
	for(Mpit it=Mp.begin();it!=Mp.end();++it) it->se=++tot;
	for(int i=1;i<=n;i++) {
		a[i]=Mp[a[i]];b[i]=Mp[b[i]];
		if(a[i]==b[i]) continue ;
		cnt[a[i]]++;
		G[b[i]].push_back(mk(a[i],0));
	}
	Xor=Mp[Xor];
	// for(int i=1;i<=n;i++) {
	// 	printf("%d ",a[i]);
	// }
	// puts("");
	// for(int i=1;i<=n;i++) {
	// 	printf("%d ",b[i]);
	// }
	// puts("");
	// printf("%d\n",Xor);
	Dfs(Xor);
	// puts("Complete");
	// for(int i=1;i<=n;i++) {
	// 	printf("%d %d\n",vis[i],cnt[i]);
	// }
	// printf("%d\n",res);
	for(int i=1;i<=n;i++) {
		if(vis[i]!=cnt[i]) {
			// printf("Dfs:%d\n",i);
			Dfs(i);
			res++;
		}
	}
	printf("%d\n",res);
	return 0;
}
