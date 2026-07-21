#include <bits/stdc++.h>
using namespace std;

long long int n, c;
vector<long long int> x, v, a, b;
long long int ans;
typedef pair<long long int, long long int> P;
vector<P> p, q;

int main(){
	cin >> n >> c;
	for(int i=0; i<n; ++i){
		long long int s, t;
		cin >> s >> t;
		x.push_back(s);
		v.push_back(t);
	}
	a.push_back(v[0]-x[0]);
	for(int i=1; i<n; ++i)
		a.push_back(v[i] - x[i] + x[i-1]);
	b.push_back(v[n-1]-c+x[n-1]);
	for(int i=1; i<n; ++i)
		b.push_back(v[n-1-i] - x[n-i] + x[n-1-i]);
	for(int i=1; i<n; ++i){
		a[i] += a[i-1];
		b[i] += b[i-1];
	}
	p.push_back(P(a[0], 0));
	q.push_back(P(b[0], n-1));
	for(int i=1; i<n; ++i){
//		a[i] = max(a[i], a[i-1]);
//		b[i] = max(b[i], b[i-1]);
		if(a[i] > p[i-1].first) p.push_back(P(a[i], i));
		else p.push_back(p[i-1]);
		if(b[i] > q[i-1].first) q.push_back(P(b[i], n-i-1));
		else q.push_back(q[i-1]);
	}
/*	for(int i=0; i<n; ++i)
		cout << i << " " << a[i] << " " <<  b[i] << endl;
*/	for(int i=0; i<n; ++i){
		ans = max(ans, p[i].first);
		ans = max(ans, q[i].first);
	}
	for(int i=0; i<n-1; ++i){
		ans = max(ans, q[i].first + p[n-i-2].first - min(c - x[q[i].second], x[p[n-i-2].second]));
	}
	cout << ans << endl;
/*	for(int i=0; i<n; ++i){
		printf("%d %lld %lld %lld %lld\n", i, p[i].first, p[i].second, q[i].first, q[i].second);
	}
*/
}
