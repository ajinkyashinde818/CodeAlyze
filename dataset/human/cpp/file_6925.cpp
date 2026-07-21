#include <bits/stdc++.h>
using namespace std;

int n, a[200000], b[200000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	reverse(b, b + n);
	int l = -1, r = -1;
	for(int i = 0; i < n; i++)
		if(a[i] == b[i]){
			int nl = i, nr = i - 1;
			for(int j = i; a[j] == b[j] && j < n; j++) nr++;
			l = nl, r = nr;
			if(r - l + 1 == n){
				cout << "No\n";
				return 0;
			}
			break;
		}
	if(l != -1){
		int j = l;
		for(int i = 0; i < l && j <= r; i++)
			if(a[i] != b[j] && a[j] != b[i])
				swap(b[i], b[j++]);
		for(int i = r + 1; i < n && j <= r; i++)
			if(a[i] != b[j] && a[j] != b[i])
				swap(b[i], b[j++]);
		if(j <= r){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for(int i = 0; i < n; i++)
		cout << b[i] << " \n"[i == n - 1];
	return 0;
}
