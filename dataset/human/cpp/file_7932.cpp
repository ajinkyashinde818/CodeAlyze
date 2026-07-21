#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void){
	int N;
	cin >> N;
	int a[N];
	long long ans[N-1];
	long long x=0;
	long long y=0;
	for(int i=0; i<N; i++){
		cin >> a[i];
		y += a[i];
	}
	for(int i=0; i<N-1; i++){
		x += a[i];
		y -= a[i];
		ans[i] = abs(x-y);
	}
	sort(ans, ans+N-1);
	cout << ans[0] << endl;
	return 0;
}
