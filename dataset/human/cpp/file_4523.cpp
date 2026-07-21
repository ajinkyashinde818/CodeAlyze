#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit
#include <cstdio>	// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>	// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()
#define DEBUG 0

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
string FILE_NAME = "testcase.A";
string NAME;
string itos (int n )
{
	stringstream ss;
	ss << n;

	return ss.str();
}

int main()
{
//	cut here before submit 
#if DEBUG
	NAME = FILE_NAME;
	int CNT = 1;
	NAME += itos (CNT );
	while (freopen (NAME.c_str() , "r", stdin ) != NULL ) {
#endif
	ios_base::sync_with_stdio(0);
	int T, D; cin >> T >> D;
	int tA, tB; cin >> tA >> tB;
	int dA, dB; cin >> dA >> dB;

	double diff = 1e100;
	for (int i = 0; i <= D; i++ ){
		for (int j = 0; j <= D; j++ ){
			int vA = i*dA, vB = j*dB;
			int cur = vA + vB;
			if (cur > D || cur < 1 ) continue;
			double curT = (double)(tA*vA + tB*vB)/(double)(vA + vB);
			double diffT = abs (curT - T );
			diff = min (diff, diffT );
		} // end for
	} // end for
	printf ("%.8lf\n", diff );

#if DEBUG
	CNT++;	// cut here before submit
	NAME = FILE_NAME;
	NAME += itos (CNT );
	} // end loop; cut here before submit
#endif			
	return 0;
}
