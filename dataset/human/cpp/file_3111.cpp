#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, cnt = 0; long x;
	cin >> n;
	long sum = 0, mi = 0x3f3f3f3f;
	for (int i = 0; i < n; i++){
		cin >> x;
		if (mi > abs(x) ) mi = abs(x);
		if (x < 0) cnt++;
		sum += abs(x);
	}
	if (cnt % 2 == 1) sum -= 2*mi;
	cout << sum << endl;
	return 0;
}
