#include<bits/stdc++.h>

using namespace std;

template<typename T>void read(T&x){x=0;int fl=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')
fl=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}x*=fl;}
template<typename T,typename...Args>inline void read(T&t,Args&...args){read(t);read(args...);}

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)

const int N = 200005;

int n, a[N], b[N];

int main(){
	read(n);
	vector<pii> vec;
	for(int i = 1; i <= n; i++)	read(a[i]);
	for(int i = 1; i <= n; i++){
		read(b[i]);
		if(b[i] == a[i])
			vec.pb(mp(b[i], i));
	}
	sort(vec.begin(), vec.end());
	int sz = vec.size(), r = 0;
	vector<bool> o(sz, false);
	for(int l = 0; l < sz; l++){
		if(o[l])	continue;
		while(r < sz && vec[r].first == vec[l].first)	r++;
		if(r == sz)	break;
		swap(b[vec[l].second], b[vec[r].second]);
		o[r] = o[l] = true;
		r++;
	}
	int pt = 1;
	for(int i = 1; i <= n; i++){
		if(b[i] == a[i]){
			while(pt <= n && !(b[pt] != a[i] && b[i] != a[pt]))	pt++;
			if(pt == n + 1)	return puts("No"), 0;
			swap(b[i], b[pt]);
			pt++;
		}
	}
	for(int i = 1; i <= n; i++)
		if(b[i] == a[i])
			return puts("No"), 0;
	puts("Yes");
	for(int i = 1; i <= n; i++)	printf("%d ", b[i]); puts("");
	return 0;
}
