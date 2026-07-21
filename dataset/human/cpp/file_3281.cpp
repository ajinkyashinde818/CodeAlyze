#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	static int n;
	static ll a[100010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&a[i]);
	}
	
	int cnt = 0;
	for(int i = 0 ; i < n ; i ++){
		if(a[i] < 0)cnt ++;
	}
	ll sum = 0;
	for(int i = 0 ; i < n ; i ++){
		sum += abs(a[i]);
	}
	if(cnt%2 == 0){
		cout << sum << endl;
		return 0;
	}
	ll MIN = 1000000000;
	for(int i = 0 ; i < n ; i ++){
		MIN = min( MIN , abs(a[i]) );
	}
	cout << sum-2*MIN << endl;
}
