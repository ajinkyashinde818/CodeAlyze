#include <bits/stdc++.h>
using namespace std;


	
int main(){
	int n,m;
	cin >> n >> m;
	if( n % 2 == 1 ){
		for(int i = 0 ; i < n ; i++){
			if(i) cout << " ";
			cout << (i%2?m:0);
		}
		cout << endl;
	}else{
		for(int i = 0 ; i < n ; i++){
			if(i) cout << " ";
			if( i <= n/2 ) cout << 0;
			else cout << m;
		}
		cout << endl;

	}
}
