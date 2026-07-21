#include<iostream>
#include<string>
using namespace std;

char a[50][50], b[50][50];
int n, m;

int main() {
	int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			bool b00 = true;
			for (int k = 0; k < m; k++){
				for (int h = 0; h < m; h++){
					if (a[i + k][j + h] != b[k][h]){
						b00 = false;
					}
				}
			}
			if (b00)sum++;
		}
	}
	if (sum != 0)cout << "Yes"; else cout << "No";
	cout << endl;
	return 0;
}
