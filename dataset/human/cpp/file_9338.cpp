#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>
#include<cstring>
using namespace std;

string c[50];
string e[50];
signed main() {
	int a, b; cin >> a >> b;
	for (int d = 0; d < a; d++)cin >> c[d];
	for (int d = 0; d < b; d++)cin >> e[d];
	for (int d = 0; d <= a - b; d++) {
		for (int f = 0; f <= a - b; f++) {
			bool k = true;
			for (int g = 0; g < b; g++) {
				for (int h = 0; h < b; h++) {
					if (e[g][h] != c[d + g][f + h])k = false;
				}
			}
			if (k) { puts("Yes"); return 0; }
		}
	}
	puts("No");
}
