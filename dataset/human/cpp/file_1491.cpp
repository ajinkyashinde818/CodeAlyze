#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m = 2;
	while(1){
		int t = m * (m - 1) / 2;
		if(t < n){
			m++;
		}else if(t == n){
			break;
		}else{
			cout << "No" << endl;
			return 0;
		}
	}
	vector<vector<int>> a(m, vector<int>());
	int cnt = 1;
	for(int i = 0; i < m - 1; i++){
		for(int j = i + 1; j < m; j++){
			a[i].emplace_back(cnt);
			a[j].emplace_back(cnt);
			cnt++;
		}
	}
	cout << "Yes" << endl;
	cout << m << endl;
	for(int i = 0; i < m; i++){
		cout << m - 1 << " ";
		for(int j = 0; j < m - 1; j++){
			cout << a[i][j];
			if(j < m - 1){
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
