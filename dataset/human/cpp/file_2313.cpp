#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 28;
int a[maxn], mini = 1e9;
int main(){
	long long s = 0;
	int n, neg = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		mini = min(abs(x), mini);
		if (x < 0)
			neg ++;
		s += abs(x);
	}
	if(neg % 2 == 0)
		cout << s;
	else
		cout << s - (2 * mini);
	return 0;
}
