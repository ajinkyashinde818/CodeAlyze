#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  char a[n][n], b[m][m];
  for (int i = 0; i < n; i++)
    scanf("%s", a[i]);
  for (int i = 0; i < m; i++)
    scanf("%s", b[i]);

  int flag;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= n - m; j++) {
      flag = 0;
      for (int k = i; k < i + m; k++) {
	for (int l = j; l < j + m; l++) {
	  if (a[k][l] != b[k - i][l - j]) {
	    flag = 1;
	    goto loop_end;
	  }
	}
      }
    loop_end: ;
      if (!flag) {
	cout << "Yes" << endl;
	return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
