//#include "stdafx.h"
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>

/*-----------------------------------------------------------------------------
　パラメータ定義
 -------------------------------------------------------------------------------*/
#define N_MAX	(200 * 1000)
#define K_MAX	(10)
#define M_MAX	(10)
#define H_MAX	(1000)
#define W_MAX	(1000)

using namespace std;

/*-----------------------------------------------------------------------------
　メモ
 -------------------------------------------------------------------------------*/
#if 0
vector<vector<vector<SDWORD>>> XXX(AAA, vector<vector<SDWORD>>(BBBB, vector<SDWORD>(CCC, -1)));
auto position = lower_bound(getValue.begin(), getValue.end(), 0);	// 0以上の要素位置を探す
auto position = upper_bound(getValue.begin(), getValue.end(), 0);	// 0より大きいの要素位置を探す
int idx_lower = distance(getValue.begin(), position);				// 0以上の要素インデックス
int eraseNum = MIN(idx_lower, delCnt);								// 要素位置が個数になる
priority_queue<int, std::vector<int>, greater<int>> que;
#endif

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define CeilN(x, n)				(((((DWORD)(x))+((n)-1))/n)*n)	/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))					/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define	BitSetV(Val,Bit)		((Val) |= (Bit))			
#define	BitTstV(Val,Bit)		((Val) & (Bit))				
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ]))
#define MAX_DWORD				(0xFFFFFFFF)
#define	MAX_SDWORD				((SDWORD)0x7FFFFFFF)
#define	MIN_SDWORD				((SDWORD)0x80000000)
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define	MIN_QWORD				((QWORD)0x0000000000000000)
#define	MAX_SQWORD				((SQWORD)0x7FFFFFFFFFFFFFFF)
#define	MIN_SQWORD				((SQWORD)0x8000000000000000)
#define M_PI					3.14159265358979323846
#define deg_to_rad(deg)			(((deg)/180)*M_PI)
#define rad_to_deg(rad)			((rad*180)/M_PI)
#define prique(T)				priority_queue<T, vector<T>, greater<T>>

typedef long					SDWORD;
typedef long long				SQWORD;
typedef unsigned long			DWORD;
typedef unsigned long long int	QWORD;
typedef pair<int, int> P;

/*-----------------------------------------------------------------------------
　自作ライブラリ
 -------------------------------------------------------------------------------*/
/* 最大公約数 */
QWORD gcd(QWORD a, QWORD b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

/* 最小公倍数 */
QWORD lcm(QWORD a, QWORD b) {
	return a * b / gcd(a, b);
}

/* 素数判定 */
bool pri(QWORD p) {
	for (QWORD i = 2; i * i <= p; ++i) if (p % i == 0) return false;
	return p > 1;
}

typedef struct edge {
	DWORD	to;
	QWORD	cost;

	edge() : to(0), cost(0) {}
	edge(DWORD argTo, QWORD argCost) : to(argTo), cost(argCost) {}

	bool operator > (const edge& e) const {
		return cost > e.cost;
	}
} EDGE;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
int main()
{
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	REP(i, N) cin >> A[i];

	B = A;
	REP(i, N - 1) {
		if (B[i] < 0) {
			B[i] *= -1;
			B[i + 1] *= -1;
		}
	}

	QWORD ans = 0;
	if (0 < B[N - 1]) {
		REP(i, B.size()) ans += B[i];
	} else {
		B[N - 1] *= -1;
		sort(B.begin(), B.end());
		REP(i, B.size()) ans += B[i];
		ans -= B[0];
		ans -= B[0];
	}
	cout << ans;
	cout << endl;
	return 0;
}
