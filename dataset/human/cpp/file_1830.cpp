#include<iostream>
#include<vector>

using namespace std;
int e[100001] = {};
bool used[200001] = {};
int main(){
	int n,m;
	cin >> n >> m;
	
	for(int i = 0;i < m;i++){
		cin >> e[i];
	}
	
	for(int i = m-1;i >= 0;i--){
		if(!used[e[i]]){
			used[e[i]] = true;
			cout << e[i] << endl;
		}
	}
	
	for(int i = 1;i <= n;i++){
		if(!used[i]){
			cout << i << endl;
		}
	}
	return 0;
}
