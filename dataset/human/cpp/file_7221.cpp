#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include<math.h>
#include<bitset>
#include<iomanip>
using namespace std;

int main() {
	int N; cin >> N;
	vector<long long>a(N);
	long long y=0;
	for (int i = 0; i < N; i++) { cin >> a[i];y += a[i]; }
	y -= a[N - 1];
	long long x=a[N-1],ans = abs(y - x) ;
	for (int i = N-2; i >0; i--) {
		y -= a[i];
		x += a[i];
		ans = min(abs(y-x), ans);
	}
	cout << ans << endl;
}
