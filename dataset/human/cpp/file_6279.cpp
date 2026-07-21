#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	cout << 32*n << endl;
}
