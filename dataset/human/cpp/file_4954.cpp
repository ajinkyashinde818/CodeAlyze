#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

int main(){
	int n,r;
	cin >> n >> r;

	if(n>=10){
		cout << r << endl;
	}else{
		cout << r + (10-n)*100 << endl;
	}

	return 0;
}
