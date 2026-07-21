#include <iostream>
using namespace std;

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int total = r + g + b;
	int mx = max(r, max(g, b));
	int mn = min(r, min(g, b));
	int mid = total - mx - mn;
	int mxu = n / mx;
	int count = 0;
	for(int i = 0; i <= mxu; i++) {
		int rval = n - (i * mx);
		int rvalu = rval / mid;
		for(int j = 0; j <= rvalu; j++) {
			int rval2 = rval - (j * mid);
			if(rval2 % mn == 0) {
				count++;
			//	cout << (rval2 / mn) << " " << rvalu << " " << mxu << endl;
			}
		}
	}
	cout << count;
	// your code goes here
	return 0;
}
