#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
int a[N],b[N],c[N];
int ta[N],tb[N];
set<pii> sc;
set<int> sa,sb;
vector<pii> ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	for(int i=1;i<=n;i++){
		ta[a[i]]++;
		sa.insert(a[i]);
		c[a[i]]++;
		tb[b[i]]++;
		sb.insert(b[i]);
		c[b[i]]++;
	}
	for(int i=1;i<=n;i++) if(c[i]>n){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=n;i++) if(c[i]) sc.insert(make_pair(-c[i],i));
	m=n;
	while(-(sc.begin()->first)<m){
		set<int>::iterator ia=sa.begin();
		set<int>::iterator ib=sb.begin();
		if((*ia)==(*ib)){
			ia++;
			if(ia==sa.end()){
				ia--;
				ib++;
			}
		}
		int x=*ia,y=*ib;
		ta[x]--;
		tb[y]--;
		sc.erase(make_pair(-c[x],x));
		c[x]--;
		if(c[x]) sc.insert(make_pair(-c[x],x));
		sc.erase(make_pair(-c[y],y));
		c[y]--;
		if(c[y]) sc.insert(make_pair(-c[y],y));
		if(!ta[x]) sa.erase(x);
		if(!tb[y]) sb.erase(y);
		ans.push_back(make_pair(x,y));
//		printf("--%d %d\n",x,y);
		m--;
	}
	if(sc.begin()->first==-m){
		int spe=sc.begin()->second;
		sa.erase(spe);
		sb.erase(spe);
		assert(ta[spe]+tb[spe]==m);
//		printf("%d %d %d\n",spe,ta[spe],tb[spe]);
		for(int i=1;i<=ta[spe];i++){
			int x=*sb.begin();
			tb[x]--;
			if(!tb[x]) sb.erase(sb.begin());
			ans.push_back(make_pair(spe,x));
//			printf("--%d %d\n",spe,x);
		}
		for(int i=1;i<=tb[spe];i++){
			int x=*sa.begin();
			ta[x]--;
			if(!ta[x]) sa.erase(sa.begin());
			ans.push_back(make_pair(x,spe));
//			printf("--%d %d\n",x,spe);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i].second);
	puts("");
	return 0;
}
