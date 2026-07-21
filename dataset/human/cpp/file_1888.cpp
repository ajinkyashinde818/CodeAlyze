#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <stdio.h>

using namespace std;

int main() {

	int q;
	cin >> q;
	vector<string> s(q);
	for (int i = 0; i < q; i++) cin >> s[i];

	// 16進数
	vector<double> ans(q, 0.0);

	vector<vector<int>> beg(q, vector<int>(32, 0));

	// 2進数に直す？
	for (int i = 0; i < q; i++) {
		//cout << i << endl;
		for (int j = 7; j >= 0; j--) {
			int value;

			switch (s[i][j]) { // めちゃきたない
			case 'a':
				value = 10;
				break;
			case 'b':
				value = 11;
				break;
			case 'c':
				value = 12;
				break;
			case 'd':
				value = 13;
				break;
			case 'e':
				value = 14;
				break;
			case 'f':
				value = 15;
				break;
			default:
				value = s[i][j] - '0';
				break;
			}
			//cout << value << endl;

			int tmp = 8;
			for (int k = 0; k < 4; k++) {
				if (value >= tmp) {
					beg[i][(7 - j) * 4 + 3 - k] = 1;
					value -= tmp;
				}
				tmp /= 2;
			}
		}
	}

	/*
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 32; j++) {
			if (j % 4 == 0) cout << " ";
			cout << beg[i][31 - j];
		}
		cout << endl;
	}*/

	vector<bool> syou(q, false);

	// こっから計算
	for (int i = 0; i < q; i++) {
		double cnt = 1.0;
		for (int j = 7; j >= 0; j--) {
			// 小数点の計算
			if (beg[i][j] == 1) {
				ans[i] += cnt;
				if(j != 7)
					syou[i] = true;
			}
			cnt *= 0.5;
		}

		cnt = 2.0;
		for (int j = 8; j < 31; j++) {
			// 整数の計算
			if (beg[i][j] == 1) {
				ans[i] += cnt;
			}
			cnt *= 2.0;
		}

		// 最後に符号
		if (beg[i][31] == 1)
			ans[i] *= -1.0;
	}

	// .0が必要
	for (int i = 0; i < q; i++) {
		if (beg[i][0] == 1) printf("%.7lf\n", ans[i]);
		else if (beg[i][1] == 1) printf("%.6lf\n", ans[i]);
		else if (beg[i][2] == 1) printf("%.5lf\n", ans[i]);
		else if (beg[i][3] == 1) printf("%.4lf\n", ans[i]);
		else if (beg[i][4] == 1) printf("%.3lf\n", ans[i]);
		else if (beg[i][5] == 1) printf("%.2lf\n", ans[i]);
		else printf("%.1lf\n", ans[i]);
	}

	return 0;
}
