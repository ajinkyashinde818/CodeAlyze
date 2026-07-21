#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		string s;
		cin >> s;
		int in = 0;
		for(int i = 0; i < s.size(); i++) {
			in *= 16;
			if('0' <= s[i] && s[i] <= '9')
				in += s[i] - '0';
			else
				in += s[i] - 'a' + 10;
		}
		if(in & (1 << 31))
			cout << '-';
		cout << ((in & ~(1 << 31)) >> 7);
		double a, b;
		a = 0.0; b = 1.0;
		for(int i = 0; i < 7; i++) {
			b /= 2;
			if(in & (1 << (6-i)))
				a += b;
		}
		stringstream sstr;
		string tmp;
		sstr.precision(10);
		sstr << a;
		sstr >> tmp;
		int j;
		for(j = tmp.size() - 1; j >= 0; j--) {
			if(tmp[j] != '0') break;
		}
		cout << '.';
		cout << string(tmp.begin() + tmp.find('.') + 1, tmp.begin() + j + 1);
		if(tmp.find('.') == j)
			cout << 0;
		cout << endl;
	}
}
