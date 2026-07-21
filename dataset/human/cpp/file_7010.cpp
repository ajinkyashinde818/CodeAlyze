#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>
#include <tuple>
#include <unordered_set>
#include <array>
#include <string>

using namespace std;
#define ll long long
#define ar array
const ll MOD=1e9+7;

ll pow(ll a, ll b) {
	ll res=1;
	while (b>0) {
		if (b&1) res*=a, res%=MOD;
		b/=2;
		a*=a;
		a%=MOD;
	}
	return res;	
}

int main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	reverse(b, b+n);
	int start=-1, end=-1;
	for (int i=0; i<n; i++) {
		if (a[i]==b[i]) {
			if (start==-1) start=i;
			end=i;
		}
	}
	bool f=0;
	if (start!=-1) {
		int i=start, j=0;
		while (i<=end) {
			if (j==start) j=end+1;
			if (j==n) {
				f=1;
				break;
			}
			if (b[i]!=a[j]&&b[j]!=b[i]) swap(b[i], b[j]), i++;
			j++;
			if (j==n) {
				f=1;
				break;
			}
		}	
	}
	if (f) {
		cout << "No";
	} else {
		cout << "Yes" << endl;
		for (int i=0; i<n; i++) {
			cout << b[i] << " ";
		}
	}
	return 0;
}
