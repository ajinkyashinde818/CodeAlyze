#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=10010; ++i){
		if(i*(i-1)/2 == n){
			cout << "Yes\n";
			cout << i << "\n";
			vector<int> v[i];
			int t = 1;
			for(int j=1; j<=i; ++j){
				for(int k=j+1; k<=i; ++k){
					v[j-1].push_back(t);
					v[k-1].push_back(t);
					++t;
				}
			}
			for(int j=0; j<i; ++j){
				cout << v[j].size() << " ";
				for(int k=0; k<v[j].size(); ++k)
					cout << v[j][k] << (k+1 == v[j].size() ? "\n" : " ");
			}
			return 0;
		}
	}
	cout << "No\n";
}
