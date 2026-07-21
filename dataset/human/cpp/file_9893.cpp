#include <bits/stdc++.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	
	long ans = 1;
	
	int unsame = 0;
	vector<int> alphabet(26,1);
	int tmp = 0;
	
	for (int i = 0; i < N; i++) {
		tmp = S.at(i) - 'a';
//cout << "dbg " << S.at(i) << ", tmp " << tmp << endl;

		alphabet.at(tmp)++;

	}
	for (int i = 0; i < 26; i++) {
		ans = ans * alphabet.at(i) % 1000000007;
	}
	


	ans = ans % 1000000007;
	
	cout << ans-1 << endl;
	
	return 0;
}
