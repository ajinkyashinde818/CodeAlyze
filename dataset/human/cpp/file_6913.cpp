#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,a[N],b[N],pos,pos2;
vector<int> v;
inline bool cmp(const int &i,const int &j) {
	return i > j;
}
signed main() {
	scanf("%lld",&n);
	for(int i = 1;i <= n;++i)
		scanf("%d",a+i);
	for(int i = 1;i <= n;++i)
		scanf("%d",b+i);
	sort(b+1,b+n+1,cmp);
	for(int i = 1;i <= n;++i)
		if(a[i] == b[i]) {
			pos = i;
			break;
		}
	if(!pos) {
		puts("Yes");
		for(int i = 1;i <= n;++i)
			printf("%d ",b[i]);
		return puts(""),0;
	}
	for(int i = 1;i <= n;++i)
		if(a[i] != a[pos] && b[i] != a[pos])
			v.push_back(i);
		else if(a[i] == b[i]) pos2 = i;
	if(v.size() >= pos2-pos+1) {
		puts("Yes");
		int cur = 0;
		for(int i = pos;i <= pos2;++i)
			swap(b[i],b[v[cur++]]);
		for(int i = 1;i <= n;++i)
			printf("%d ",b[i]);
		return puts(""),0;
	}
	else puts("No");
	return 0;
}
