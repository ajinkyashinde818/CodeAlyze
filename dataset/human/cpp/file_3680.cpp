#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x[500005],y[10],z[10];
ll t,i,j;
ll sum;
ll p,q;
ll a,n;

int main (){
	cin >> n;
	for(i=0;i<n;i++){
		cin >> x[i];
		if(x[i] < 0)a++;
	}
		for(i=0;i<n;i++){
			sum += abs(x[i]);
		}
	for(i=0;i<n;i++){
		x[i] = abs(x[i]);
	}
	if(a % 2 == 1){
		sort(x,x+n);
		sum -= 2 * x[0];
	}
	cout << sum << endl;


	return 0;
}
