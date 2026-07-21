#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <array>
using namespace std;

#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define INIT(a,v) memset(a,v,sizeof(a))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

#define SPC << " " <<
#define DEBUG(x) cerr << #x << " = "; cerr << x << endl;
#define DEBUG_ITER(x) cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl;

typedef pair<int,int> PII;
typedef long long int64;
typedef vector<int> VI;

int n;
int a[200000],b[200000];

int main() {
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	REP (i,n) scanf("%d",&a[i]);
	REP (i,n) scanf("%d",&b[i]);
	reverse(b,b+n);
	int f=0,t=n-1;
	REP (i,n) {
		if (a[i]==b[i] && a[f]!=a[i] && b[f]!=b[i]) { swap(b[i],b[f]); f++; }
		if (a[i]==b[i] && a[t]!=a[i] && b[t]!=b[i]) { swap(b[i],b[t]); t--; }
		if (a[i]==b[i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	REP (i,n) {
		if (i!=0) printf(" ");
		printf("%d",b[i]);
	}
	printf("\n");
	return 0;
}
