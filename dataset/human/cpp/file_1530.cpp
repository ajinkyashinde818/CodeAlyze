#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<random>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#define MAX 100002

int n;

int ar[1002][1002];

int main() {
	cin >> n;
	if (n == 1) {
		puts("Yes");
		puts("2");
		cout << 1 << " " << 1 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	if (n == 3) {
		puts("Yes");
		cout << 3 << endl;
		cout << 2 << " " << 1 << " " << 2 << endl;
		cout << 2 << " " << 3 << " " << 1 << endl;
		cout << 2 << " " << 2 << " " << 3 << endl;
		return 0;
	}
	ar[0][0] = 1;
	ar[0][1] = 1;
	ar[0][2] = 2;
	ar[1][0] = 3;
	ar[1][1] = 2;
	ar[1][2] = 3;
	int card = 3;
	int val = 3;
	while (val < n) {
		int nex_l = val + 1;
		int nex_r = val +card;
		for (int i = 0; i < card; i++) {
			ar[card - 1][i] = nex_l + i;
		}
		for (int i = 0; i < card; i++) {
			ar[i][card] = nex_l + i;
		}
		card++;
		val = nex_r;
	}
	if (val != n) {
		puts("No");
		return 0;
	}
	puts("Yes");
	cout << card << endl;
	for (int i = 0; i < card; i++) {
		cout << card - 1;
		for (int j = 0; j < card - 1; j++) {
			printf(" %d", ar[j][i]);
		}
		puts("");
	}
	return 0;
}
