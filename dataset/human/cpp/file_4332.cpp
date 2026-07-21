#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N];
map<int,int>p;
inline int bel(int i){
	return i==p[i]?i:p[i]=bel(p[i]);
}
int main(){
	cin>>n;
	multiset<int>c,d;
	for(int i=1;i<=n;++i)
		cin>>a[i],a[0]^=a[i],c.insert(a[i]);
	c.insert(a[0]);
	for(int i=1;i<=n;++i)
		cin>>b[i],b[0]^=b[i],d.insert(b[i]);
	d.insert(b[0]);
	if(c!=d)
		return!~puts("-1");
	for(int i=1;i<=n;++i)
		if(a[i]!=b[i])
			p[a[i]]=a[i];
	p[a[0]]=a[0];
	int s=-1;
	for(int i=1;i<=n;++i)
		if(a[i]!=b[i])
			p[bel(a[i])]=bel(b[i]),++s;
	for(auto e:p)
		if(e.first==e.second)++s;
	cout<<s<<endl;
}
