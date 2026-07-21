#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> a;
  for (int i = 0; i < n; i++) {
	string s;
	cin >> s;
	a.push_back(s);
  }
  vector<string> b;
  for (int i = 0; i < m; i++) {
	string s;
	cin >> s;
	b.push_back(s);
  }
  bool flag = false;
  for (int i = 0; i <= n - m; i++) {
	for (int j = 0; j <= n - m; j++) {
	  bool check = true;
	  for (int k = i; k < m + i; k++) {
		for (int l = j; l < m + j; l++) {
		  if (b[k - i][l - j] != a[k][l]) {
			check = false;
		  }
		}
	  }
	  if (check) {
		flag = true;
		break;
	  }
	}
  }
  if (flag) {
	cout << "Yes" << endl;
	return 0;
  }
  else {
	cout << "No" << endl;
	return 0;
  }
  return 0;
}
