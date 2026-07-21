#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;
#define INF 100000000000

ll llAbs(ll num){
	if(num < 0) num = num * -1;
	return num;
}

int main()
{
	int n;
	cin>>n;
	ll *x = new ll[n];
	ll *y = new ll[n];
	int *a = new int[n];
	rep(i,n){
		cin>>a[i];
	}
	x[0] = a[0];
	for(int i = 1 ; i < n; i++){
		x[i] = x[i-1] + a[i];
	}
	y[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--){
		y[i] = y[i+1] + a[i];
	}
	ll ans = INF;
	for(int i = 0; i < n-1; i++){
		ans = min(ans, llAbs(x[i] - y[i+1]));
		//cout<<llAbs(x[i] - y[i+1])<<endl;
		//cout<<x[i]<<" "<<y[i+1]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
