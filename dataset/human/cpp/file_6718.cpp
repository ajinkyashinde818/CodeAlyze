#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main() {
	std::string s; cin >> s;
	
	int c = -1, d = -1, e = -1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '.') c = i;
		if(s[i] == '(') d = i;
		if(s[i] == ')') e = i;
	}
	
	if(~d) {
		i64 B = 1, C = 1;
		for(int i = 0; i < e - d - 1; i++) B *= 10; --B;
		for(int i = 0; i < d - c - 1; i++) C *= 10; B *= C;
		std::string t = "";
		for(int i = 0; i < d; i++) if(s[i] != '.') t += s[i];
		std::string X = t + s.substr(d + 1, e - d - 1);
		std::string Y = t;
		i64 x = std::stoll(X), y = std::stoll(Y);
		i64 A = (x - y);
		i64 G = std::__gcd(A, B);
		
		cout << A / G << "/" << B / G << endl;	
	} else {
		i64 B = 1;
		for(int i = 0; i < s.size() - c - 1; i++) {
			B *= 10;
		}
		std::string t = "";
		for(auto v : s) if(v != '.') t += v;
		i64 A = std::stoll(t);
		i64 G = std::__gcd(A, B);
		
		cout << A / G << "/" << B / G << endl;
	}
	return 0;
}
