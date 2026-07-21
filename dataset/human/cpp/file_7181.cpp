//ABC067C
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <climits>
#include <cfloat>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long int> a(n);
	long long int l = 0, r = 0;
	for(int i=0;i<n;i++){
		cin >> a.at(i);
		r += a.at(i);
	}
	l += a.at(0);
	r -= a.at(0);
	long long int ans = abs(r-l);
	for(int i=1;i<n-1;i++){
		l += a.at(i);
		r -= a.at(i);
		ans = min(ans,abs(l-r));
	}
	cout << ans << endl;
	return 0;
}
