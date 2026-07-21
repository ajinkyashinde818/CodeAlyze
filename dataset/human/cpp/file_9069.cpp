#include <iostream>
#include <vector>
using namespace std;

bool match(vector<string> nv, vector<string> mv, int x, int y){
	for(int i=0; i<mv.size(); i++){
		if(mv[i] != nv[x+i].substr(y, mv.size())) return false;
	}
	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> nv(n);
	vector<string> mv(m);
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		nv[i] = s;
	}
	for(int i=0; i<m; i++){
		cin >> s;
		mv[i] = s;
	}
	for(int i=0; i<n-(m-1); i++){
		for(int j=0; j<n-(m-1); j++){
			if(match(nv, mv, i, j)) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}
