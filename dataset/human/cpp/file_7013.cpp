#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	reverse(b.begin(), b.end());
	int l = 0, r = -1, c;
	for(int i = 0; i < n; i++)
		if(a[i]==b[i]){
			l = i; c = a[i]; 
			break;
		}
	for(int i = n-1; 0 <= i; i--)
		if(a[i]==b[i] && a[i]==c){
			r = i; break;
		}
	for(int i = 0; i < n && l <= r; i++)
		if(a[i]!=c && b[i]!=c) swap(b[i], b[l++]);
	if(l<=r) cout << "No\n";
	else {
		cout << "Yes\n";
		for(int i = 0; i < n; i++) cout << b[i] << ' ';
		cout << '\n';
	}
	return 0;
}
