/********************************************
 *Author*        :ZZZZone
 *Created Time*  : 六  4/21 20:16:41 2018
 * Ended  Time*  : 六  4/21 20:39:09 2018
*********************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 1e5;

LL x[MAXN+5], v[MAXN+5];
int n;
LL C;


struct Node{
	int pos;
	LL sum;
}fl, fr;
LL qr[MAXN+5], ql[MAXN+5];

void Init(){
	scanf("%d %lld", &n, &C);
	for(int i = 1; i <= n; i++){
		scanf("%lld %lld", &x[i], &v[i]);
	}
}

void Solve(){
	LL sum = 0;
	for(int i = 1; i <= n; i++){
		sum += v[i];
		ql[i] = max(ql[i-1], sum - x[i]);
	}
	sum = 0LL;
	for(int i = n; i >= 1; i--){
		sum += v[i];
		qr[i] = max(qr[i+1], sum - (C-x[i]));
	}
	sum = 0LL;
	LL ans = 0LL;
	for(int i = 0; i <= n; i++){
		LL tmp = max(ql[i] - x[i] + qr[i+1], ql[i]);
		ans = max(ans, tmp);
	}
	sum = 0LL;
	for(int i = n+1; i >= 1; i--){
		LL tmp = max(qr[i] - (C-x[i]) + ql[i-1], qr[i]);
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
}

int main()
{
	Init();
	Solve();
    return 0;
}
