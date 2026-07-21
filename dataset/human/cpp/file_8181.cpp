#include <iostream>
#include <algorithm>
using namespace std;

long long a[200010];

int main(void){
	int n;
	long long ans=0, x=0, s=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		s += a[i];
	}
	for(int i=0; i<n-1; i++){
		x += a[i];
		if(i==0 || ans>abs(2*x-s)) ans = abs(2*x-s);
	}
	cout << ans << endl;
	return 0;
}
