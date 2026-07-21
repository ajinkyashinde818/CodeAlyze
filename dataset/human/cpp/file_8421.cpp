#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
	int n,m;
	string S;
	vector<string> s,s2;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> S;
		s.push_back(S);
	}
	for(int i=0;i<m;i++){
		cin >> S;
		s2.push_back(S);
	}
	
	bool ok;
	for(int i=0;i+m<=n;i++){
		for(int j=0;j+m<=n;j++){
		ok=true;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(s[i+k][j+l]!=s2[k][l]){
						ok=false;
					}
				}
			}
			if(ok) goto bb;
		}
	}
	bb:;
	cout << (ok?"Yes":"No") << endl;
	return 0;
}
