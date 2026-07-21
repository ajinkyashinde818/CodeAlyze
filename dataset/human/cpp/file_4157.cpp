#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
#include<functional>
#include<utility>
#include<tuple>
#include<math.h>
using namespace std;
const long long int big = 1152921504606846976;
double dig = 98765432100000000;//10の9乗を軽く超えます
//xi,yi,5に合うのは
//  xj+yj+5==xi+yi  &&  xi-yi+5>=xj-yj>=xi-yi-5であるもの
//xj+yj,xj-yj,xi+yi,xi-yiを受け取って、それができるのをキューに入れて保持
//チェビシェフ距離の考え方

int main(void) {
	int  i,j,a,b,c,e,N,ter;//mt->そこまでの時間
	long double d,mt;
	static long double x[1010] = { 0 };
	static long double y[1010] = { 0 };
	static long double r[1010] = { 0 };
	static long double time[1010] = { 0 };
	priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>> pque;
	scanf("%d %d %d %d", &a, &b, &c, &e);
	x[0] = a; y[0] = b; x[1] = c; y[1] = e;
	r[0] = 0; r[1] = 0; time[0] = dig; time[1] = dig;
	scanf("%d", &N);
	for (i = 2; i < N + 2; i++) {
		scanf("%d %d %d", &a, &b, &c);
		x[i] = a;
		y[i] = b;
		r[i] = c;
		time[i] = dig;//無限大で初期化
	}
	pque.push(make_pair(0, 0));//time[0]=0;
	while (!pque.empty()) {
		mt = pque.top().first;
		ter = pque.top().second;
		pque.pop();
		if (time[ter]<mt) { continue; }//もしtime[ter]がすでにある時間より短いなら飛ばす
		for (i = 1; i < N+2; i++) {//0に飛ばす必要はない
			d = hypot(x[ter] - x[i], y[ter] - y[i]);
			d -= (r[ter]+r[i]);
			if (d < 0) { d = 0; }
			if (mt + d < time[i]) { pque.push(make_pair(mt + d, i)); time[i] = mt + d; }
		}
		
	}
	printf("%.16Lf", time[1]);
	return 0;
}
