#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef pair <ii,int> iii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 100005;

LL  res, c, x[N], akt, last, best, cl[N], acl[N];
int n, v[N], i;

int main() {
scanf("%d %lld", &n, &c);
for (i=0;i<n;i++) scanf("%lld %d", &x[i], &v[i]);
res = 0;
akt = 0;
last = 0;
best = -INF * 1LL * INF;
for (i=0;i<n;i++) {
	akt -= (x[i] - last);
	akt += v[i]; 
	last = x[i];
	best = max(best, akt);
	cl[i] = best;
	//printf("%d %lld\n", i, cl[i]);
}
res = max(res, cl[n - 1]);
akt = 0;
last = c;
for (i=n-1;i>=1;i--) {
	akt -= (last - x[i]);
	akt -= (last - x[i]);
	last = x[i];
	akt += v[i];
	res = max(res, akt + cl[i - 1]);
}

akt = 0;
last = c;
best = -INF * 1LL * INF;
for (i=n-1;i>=0;i--) {
	akt -= (last - x[i]);
	akt += v[i];
	last = x[i];
	best = max(best, akt);
	acl[i] = best;
	//printf("%d %lld\n", i, acl[i]);
}
res = max(res, acl[0]);
akt = 0;
last = 0;
for (i=0;i<n-1;i++) {
	akt -= (x[i] - last);
	akt -= (x[i] - last);
	last = x[i];
	akt += v[i];
	res = max(res, akt + acl[i + 1]);
}
printf("%lld\n", res);

return 0;
}
