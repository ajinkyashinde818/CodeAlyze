#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_template_matching(void) {
	int n, m;
	string a[50];
	string b[50];
	int match_cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int sub = n - m;

	for (int i = 0; i <= sub; i++) {
		for (int j = 0; j <= sub; j++) {
			match_cnt = 0;
			for (int k = 0; k < m; k++) {
				
				string a_pick = a[k + i].substr(j,m);
				string b_pick = b[k];
				//cout << i << "," << j <<","<<k<< endl;
				//cout << "a:" << a_pick << endl;
				//cout << "b:" << b_pick << endl;
				if (a_pick != b_pick)break;
				else {
				//	cout << "match!" << endl;
					match_cnt++;
				}
			}
			if (match_cnt == m) {
				cout << "Yes" << endl;
				exit(0);
			}
		}
	}
	cout << "No" << endl;
}

int main()
{
	b_template_matching();
    return 0;
}
