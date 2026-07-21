#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	long long int a[100005], b[100005];
	int minuscnt = 0;
	long long int sum = 0LL;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]<0){
			minuscnt++;
		}
		b[i] = abs(a[i]);
		sum += b[i];
	}
	if(minuscnt%2==0){
		cout << sum << endl;
		return 0;
	}
	sort(b, b+n);
	cout << sum-b[0]*2 << endl;
	return 0;
}
