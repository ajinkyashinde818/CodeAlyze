#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

LL N, L;

struct node {
	node* ch[2];
	node() {
		ch[0] = ch[1] = nullptr;
	}
	void putstr(const char *str) {
		if (*str == '\0')return;
		if (!ch[(*str) - '0'])
			ch[(*str) - '0'] = new node();
		ch[(*str) - '0']->putstr(str + 1);
	}
	//最後の子か？
	bool eval() {
		if (!ch[0] && !ch[1])return true;
		if (ch[0] && ch[1]) {
			if (ch[0]->eval() && ch[1]->eval()) {
				ch[0] = ch[1] = nullptr;
				return true;
			}
		}
		return false;
	}
	int grundy(int d) {
		if (!ch[0] && !ch[1]) {
			//ここに文字列がある⇒黒
			return 0;
		}
		if (!ch[0] && ch[1]) {
			//片方(ch0)は白い木　もう片方(ch1)は灰色木
			int val = ch[1]->grundy(d + 1);
			LL chim = L - (LL)d;
			LL lev = 0;
			while (chim % 2 == 0) {
				lev++;
				chim /= 2;
			}
			val ^= (1 << lev);
			return val;
		}
		if (ch[0] && !ch[1]) {
			//片方(ch1)は白い木　もう片方(ch0)は灰色木
			int val = ch[0]->grundy(d + 1);
			LL chim = L - (LL)d;
			LL lev = 0;
			while (chim % 2 == 0) {
				lev++;
				chim /= 2;
			}
			val ^= (1 << lev);
			return val;
		}
		//両方灰色木
		return ch[0]->grundy(d + 1) ^ ch[1]->grundy(d + 1);
	}
};

char str[114514];

int main(void)
{
	node root;
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		root.putstr(str);
	}
	root.eval();
	bool ans = root.grundy(0);
	if (ans) {
		cout << "Alice\n";
	}
	else {
		cout << "Bob\n";
	}
	return 0;
}
