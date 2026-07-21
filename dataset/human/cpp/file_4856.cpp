#include <bits/stdc++.h>
using namespace std;

//factorial
int fact(int n) {
	int a = 1;
	for (int i = 1;i <= n;i++) a *= i;
	return a;
}

int n, r;
int main(){
	cin >> n >> r;
	if (n < 10)r += 100 * (10 - n);
	cout << r << endl;
}
