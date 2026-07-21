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

	long res;
	
	long R , G , B , N; cin >> R >> G >> B >> N;
	long r, g, b;
	for (int i = 0; i <= 3000; i++) {
		for (int j = 0; j <= 3000; j++) {
			r = i * R;
			g = j * G;
			b = N - r - g;
            
			if (b >= 0) if (b % B == 0) if (b / B <= 3000) res++;
	   }
	}

	cout << res << endl;
}
