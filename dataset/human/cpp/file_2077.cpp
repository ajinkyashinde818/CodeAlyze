#include <iostream>

using namespace std;
long long a[100010],mn = 10000000000,sum = 0,mx = 0;
int main(){
	int i,n,cnt = 0;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		if(a[i]<0){
			cnt++;
		}
		if(a[i]<0) a[i] = -a[i];
		mn = min(a[i],mn);
		sum += a[i];
	}
	if(cnt&1){
		cout << sum - 2*mn << endl;
	}else{
		cout << sum << endl;
	}
}
