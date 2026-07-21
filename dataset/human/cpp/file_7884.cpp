#include <bits/stdc++.h>
using namespace std;

long long n, h, a[200001];
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h;
		a[i] = a[i-1]+h;
	}
	h = INT_MAX;
	for(int i = 1; i < n; i++) h = min(h, abs(a[i]-(a[n]-a[i])));
	cout << h;
}
