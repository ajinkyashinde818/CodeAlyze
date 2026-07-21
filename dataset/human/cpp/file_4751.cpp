#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;

int main() {
	vector<vector<vector<long long>>> U(10000,vector<vector<long long>>(100, vector<long long>(12,1000)));

	int N, M;
	cin >> N >> M;
	cout << M + (max(0, 10 - N) * 100);
}
