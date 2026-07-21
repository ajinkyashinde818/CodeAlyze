#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long b = 0,c = 0;
  	cin >> n;
  	vector<long> a(n);
	for(int i = 0; i<n;i++) {
		cin >> a[i];
		c += a[i];
	}
	int min = 1E9 * 3;
  	for(int i = 0; i<n-1;i++) {
		b += a[i];
		c -= a[i];
  		if(min > abs(b-c))
	  		min = abs(b-c);
	}
	cout << min << endl;
	
}
