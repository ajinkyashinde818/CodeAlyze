#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> e(m);
	vector<bool> b(n+1,true);
	for(int i=0;i<m;i++) cin >> e[i];
	reverse(e.begin(),e.end());
	for(int i=0;i<m;i++){
		if(b[e[i]]){
			cout << e[i] << endl;
			b[e[i]]=false;
		}	
	}
	for(int i=1;i<=n;i++){
		if(b[i]){
			cout << i << endl;
			b[i]=false;
		}	
	}
  return 0;
}
