#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>
#include<functional>
#include<limits.h>
#include<string.h>
#include<algorithm> 
#define int long long
using namespace std;

int S[1005][1005];
signed main() {
	int n; cin >> n;
	if (n == 1) {
		puts("Yes");
		cout << 2 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 1 << " " << 1 << endl;
	}
	else {
		for (int i = 2; i <= 1000; i++) {
			if (i*(i - 1) / 2 == n) {
				int sum = 1;
				puts("Yes");
				cout << i << endl;
				for (int j = 0; j < i; j++) {
					for (int k = 0; k < i - j; k++) {
						S[j][j + k] = sum + k;
						S[j + k + 1][j] = sum + k;
					}
					sum += i - j - 1;
				}
				for (int j = 0; j < i; j++) {
					cout << i - 1;
					for (int k = 0; k < i - 1; k++) {
						cout << " " << S[j][k];
					}
					cout << endl;
				}
				return 0;
			}
		}
		puts("No");
	}
}
