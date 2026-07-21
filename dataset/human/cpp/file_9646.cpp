#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for(int i=0; i<n; i++) cin >> a.at(i);
	for(int i=0; i<m; i++) cin >> b.at(i);
	bool judge=false;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i+m-1>=n || j+m-1>=n) continue;
			bool match=true;
			for(int y=0; y<m; y++){
				for(int x=0; x<m; x++){
					if(a.at(i+y).at(j+x)!=b.at(y).at(x)){
						match=false;
					}
				}
			}
			if(match) judge=true;
		}
	}
	if(judge) cout << "Yes" << endl;
	else cout << "No" << endl;
}
