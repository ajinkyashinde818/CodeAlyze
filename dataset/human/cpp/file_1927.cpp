#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string abc = "0123456789abcdef";
	string z1 = "01";
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		string b = "";
		for (int j = 0; j < a.size(); j++) {
			string c = "";
			int d;
			for (int k = 0; k < abc.size(); k++) {
				if (a[j] == abc[k]) {
					d = k;
					break;
				}
			}
			for (int k = 0; k < 4; k++) {
				c += z1[d%2];
				d /= 2;
			}
			for (int k = 3; k >= 0; k--) {
				b += c[k];
			}
		}
		string f = b.substr(0, 1);
		string g = b.substr(1, 24);
		string h = b.substr(25);
		long long int kazu = 0;
		for (int i = g.size()-1; i >= 0; i--) {
			if (g[i] == '1') {
				kazu += pow(2, g.size()-1-i);
			}
		}
		long double kazu2 = 0.0;
		for (int i = 0; i < h.size(); i++) {
			if (h[i] == '1') {
				kazu2 += pow(2.0, -1-i);
			}
		}
		if (f[0] == '1') {
			cout << '-';
		}
		int p = kazu2 * 10.0;
		kazu2 = kazu2 *10.0 - p;
		string k = "";
		while (kazu2 != 0.0) {
			//cout << k << ' ' << kazu2 << endl;
			k += abc[p];
			p = kazu2 * 10.0;
			kazu2 = kazu2 * 10.0 - p;
		}
		k += abc[p];
		/*if (k.find('.') != string::npos) {
			k = k.substr(2);
		}*/
		cout << kazu << '.' << k << endl;
	}
	return 0;
}
