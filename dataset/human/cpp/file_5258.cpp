#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int n, r;
	cin >> n >> r;
	if(n <= 10){
		cout << r+(10-n)*100 << endl;
	}else{
		cout << r << endl;
	}
}
