#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	const int k = (n / 2) + 1;
	for(int i = 0; i < n; ++i){
		if(i != 0){ cout << " "; }
		cout << (i < k ? 0 : m);
	}
	cout << endl;
	return 0;
}
