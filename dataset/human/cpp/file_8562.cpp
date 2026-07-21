#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector <string> A;
  vector <string> B;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    A.push_back(s);
  }
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    B.push_back(s);
  }

  if(n == m) {
    for(int i = 0; i < n; i++) {
      if(A[i] != B[i]) {
	cout << "No" << endl;
	return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
  }

  for(int i = 0; i < n - m; i++) {
    for(int j = 0; j < n - m; j++) {
      // A[i][j]がスタート
      bool flag = true;
      for(int k = 0; k < m; k++) {
	for(int l = 0; l < m; l++) {
	  if(A[i + k][j + l] != B[k][l]) {
	    flag = false;
	    break;
	  }
	}
	if(!flag) {
	  break;
	}
      }
      if(flag) {
	cout << "Yes" << endl;
	return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
