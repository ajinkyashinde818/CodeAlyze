#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long int ll;
int main(){
	int N;
	int a[200000];
	ll sum_x, sum_y;

	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];

	sum_y = 0;
	for(int i = 1; i < N; i++){
		sum_y += a[i];
	}
	sum_x = a[0];
	ll ans = abs(sum_x - sum_y);
	for(int i = 1; i < N - 1; i++){
		sum_x += a[i];
		sum_y -= a[i];
		if(abs(sum_x - sum_y) < ans) ans = abs(sum_x - sum_y);
	}
	cout << ans << endl;
	return 0;
}
