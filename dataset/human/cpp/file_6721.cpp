#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solver {
public:
	static void solve() {
		string s;
		cin >> s;

		int len = 0;
		bool in = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ')')in = false;
			if (in)len++;
			if (s[i] == '(')in = true;
		}

		if (len == 0) {
			int child = 0;
			int parent = 1;
			bool inDot = false;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '.') {
					inDot = true;
					continue;
				}

				child *= 10;
				child += s[i] - '0';

				if (inDot)parent *= 10;
			}
			int gcd = GCD(child, parent);
			cout << child / gcd << '/' << parent / gcd << endl;
		}
		else {
			bool inDot = false;
			int dotCnt = 0;
			int child = 0;
			for (int i = 0; i < s.size() - len - 2; i++) {
				if (s[i] == '.') {
					inDot++;
					continue;
				}

				child *= 10;
				child -= s[i] - '0';
				if (inDot)dotCnt++;
			}
			child += -child * pow(10, len);
			child += stoi(s.substr(s.size() - len - 1, len));
			int parent = (pow(10, len) - 1) * pow(10, dotCnt);
			int gcd = GCD(child, parent);
			cout << child / gcd << '/' << parent / gcd << endl;
		}
	}

	static int GCD(int x, int y) {
		if (y == 0)return x;
		else return GCD(y, x % y);
	}
};

int main() {
	Solver::solve();
}
