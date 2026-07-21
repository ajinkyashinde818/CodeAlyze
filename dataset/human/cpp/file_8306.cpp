#include<iostream>
#include<cmath>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include<map>
#include <utility>
#include <math.h>
using namespace std;
int a = 0, b = 0, c = 0, d = 0, e[100010] = {}, f[100010];
double syo = 0, su = 0;
long long   mur = 0, kmr = 0, yju = 0, counto[5003], counto1[5003];
char fir, sec = 'z', mado[52][52],homu[52][52];
string rik[55],mrsm[55], tok[25003];
bool mazi[110], gi[110], zi, manji;
pair<int, int>n[110];
vector<int> aa[50] = {}, cc;
vector<char> bb,dd;
map<char, int>zis,uuu;
int gcd(int a, int b) {
	int d;
	if (a > b) {
		int t = b;
		b = a;
		a = t;
	}
	while ((d = b % a) != 0) {
		b = a;
		a = d;
	}
	return a;
}
int main()
{
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> rik[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> mrsm[i];
	}
	for (int i = 0; i <= a -b; i++) {
		for (int j = 0; j <= a - b; j++) {
			for (int k = 0; k < b; k++) {
				if (rik[k+i].substr(j, b) == mrsm[k]) {
					c++;
				}
				else { c = 0; }

			}
			if (c == b) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
	return 0;
}
