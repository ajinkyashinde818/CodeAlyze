#include <iostream>
#include <string>
//#include <conio.h>
using namespace std;
bool calc(string *strA, string *strB, int n, int m, int diff, int line, int column);
int main() {
	
	int n = 0;
	int m = 0;
	cin >> n;
	cin	>> m;
	string *strA = new string[n];
	string *strB = new string[m];
	for (int i = 0; i < n; i++) {
		cin >> strA[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> strB[i];
	}
	int line = 0;
	int column = 0;
	bool isIncludeA = false; 
	if (n < m) goto Last;
	isIncludeA = calc(strA, strB,n, m, n-m, line,column);
	Last:
	if (isIncludeA) cout << "Yes";
	else cout << "No";
	//line 縦,column 横
	//_getch();
}
bool calc(string *strA, string *strB, int n, int m, int diff, int line, int column) {
	for (int i = 0; i < m; i++) {
		if (strA[i + line].substr(column, m) == strB[i]) {
			if (i == m - 1) {
				return true;
			}
			else { 
				continue;
			}
		}
		else {
			if (diff > column) {
				column++;
			}
			else
			{
				if (diff > line ) {
					line++;
					column = 0;
				}
				else {
					return false;
				}

			}
			//cout << "n " << diff << " line " << line << " column " << column << endl;
			calc(strA, strB, n, m, diff, line, column);
			break;
		}
	}

}
