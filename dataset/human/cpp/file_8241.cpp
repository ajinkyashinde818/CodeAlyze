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

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
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

typedef long					SDWORD;
typedef long long				SQWORD;
typedef unsigned long			DWORD;
typedef unsigned long long int	QWORD;
typedef pair<int, int>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
#define N_MAX	(200 * 1000)
#define K_MAX	(10)
#define M_MAX	(10)
#define H_MAX	(1000)
#define W_MAX	(1000)

int main()
{
	int N;
	cin >> N;

	SQWORD totalSize = 0;
	vector<SQWORD> a(N);
	REP(i, N) {
		cin >> a[i];
		totalSize += a[i];
	}

	SQWORD sum = 0;
	SQWORD ans = MAX_SQWORD;
	REP(i, N - 1) {
		sum += a[i];
		SQWORD diff = totalSize - 2 * sum;
		ans = min(ans, abs(diff));
	}

	cout << ans;
	cout << endl;
	return 0;
}
