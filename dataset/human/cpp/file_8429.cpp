#include <iostream>
using namespace std;

int main() {
	char a[51][51], b[51][51];
	int n, m;
	bool flag = false;
	cin >> n >> m;
	if(n<m){
		cout << "No" << endl;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin >> b[i][j];
		}
	}
	for(int i=0;i<n-m+1;i++){
		for(int j=0;j<n-m+1;j++){
			int tmp_i = i;
			int tmp_j = j;
			int cnt = 0;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(a[tmp_i][tmp_j] == b[k][l]){
						cnt++;
					}
					tmp_j++;
				}
				tmp_i++;
				tmp_j = j;
			}
			if(cnt == m*m){
				flag = true;
			}
		}
	}
	if(flag == true){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	
	return 0;
}
