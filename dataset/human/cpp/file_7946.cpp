#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
using namespace std;

long gcd(long x, long y) { if (x > y) { return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; }return x; }
long lcm(long x, long y) { return(x / gcd(x, y)) * y; }
void indexsort(long* first, long* last, long* func) { sort(first, last, [&](long a, long b) {return func[a] < func[b]; }); }
//--------------------

int main() {

	long N; cin >> N;
	long res = INT_MAX;
	long a[200009] = {}; for (int i = 0; i < N; i++) cin >> a[i];
    
	long sum[200009] = {}; sum[0] = a[0]; for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 0; i < N - 1; i++) res = min(res, abs((sum[N - 1] - sum[i]) - sum[i]));
	
    cout << res << endl;
}
