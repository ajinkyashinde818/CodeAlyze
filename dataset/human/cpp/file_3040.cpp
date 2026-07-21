#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n,minus_counter=0;
	long res = 0;
	cin >> n;
	vector<int> a;
	for(int i=0;i<n;++i){
		int k;
		cin >> k;
		if(k < 0){
			minus_counter++;
		}
		a.push_back(abs(k));
	}
	sort(a.begin(),a.end());
	if(minus_counter%2)a[0] *= -1;
	for(int i=0;i<n;i++){
		res += a[i];
	}
	cout << res << endl;
}
