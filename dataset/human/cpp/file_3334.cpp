#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int main(){
	int n;
	cin >> n ;
	vector<long long int> v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}
	
	bool f = false;
	long long int cnt = 0;
	long long int m = 10e9+4;
	long long int sum = 0;
	for(int i=0;i<n;++i){
		m = min(m,abs(v[i]));
		if(v[i] < 0){
			cnt++;
			sum += -1*v[i];
		}else{
			sum += v[i];
		}
		if(v[i] == 0) f = true;
	}
	
	//cout << f << " " << cnt << " " << sum <<endl;
	if(f || cnt%2 == 0) cout << sum << endl;
	else{
		cout << sum - m*2 << endl;
	}
	
	return 0;
}
