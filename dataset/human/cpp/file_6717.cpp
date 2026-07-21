#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string S;
int e, f1, f2, g1, g2;
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
int main() {
	cin >> S; string T; bool flag = false;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '.') { e = stoi(T); T = ""; }
		else if (S[i] == '(') { if (T.size() >= 1) { f1 = stoi(T); } f2 = pow(10, T.size()); T = ""; flag = true; }
		else if (S[i] == ')') { g1 = stoi(T); g2 = pow(10, T.size()) - 1; T = ""; }
		else { T += S[i]; }
	}
	if (flag == false) { f1 = stoi(T); f2 = pow(10, T.size()); g1 = 0; g2 = 1; }
	int E1 = e*f2*g2 + f1*g2 + g1, E2 = f2*g2;
	cout << E1 / gcd(E1, E2) << "/" << E2 / gcd(E1, E2) << endl;
	return 0;
}
