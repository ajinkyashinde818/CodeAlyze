#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,m;
	bool flag = false;
	string s[50],t[50];
	cin >> n >> m;
	for(int i = 0;i < n;i++) cin >> s[i];
	for(int i = 0;i < m;i++) cin >> t[i];
	for(int i = 0;i < n - m + 1;i++){
		for(int j = 0;j < n - m + 1;j++){
			bool f = true;
			for(int k = 0;k < m;k++){
				for(int l = 0;l < m;l++){
					if(s[i + k][j + l] != t[k][l]) f = false;
				}
			}
			if(f) flag = true;
		}
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
