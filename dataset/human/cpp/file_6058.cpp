#include <bits/stdc++.h>

using namespace std;

int n;
long long c;

pair <long long, int> a[100005];

long long cw[100005], ccw[100005], dp1[100005], dp2[100005];

int main(){
	scanf("%d%lld", &n, &c);
	
	for(int i = 0; i < n; i++)
	scanf("%lld%d", &a[i].first, &a[i].second);
	
	long long res = 0;
	
	for(int i = 0; i < n; i++){
		if(i == 0)
		cw[i] = a[i].second - a[i].first;
		else
		cw[i] = cw[i - 1] + a[i].second - (a[i].first - a[i - 1].first);
		
		if(i == 0)
		dp1[i] = cw[i];
		else
		dp1[i] = max(dp1[i - 1], cw[i]);
		
		res = max(res, cw[i]);
	}
	
	for(int i = n - 1; i >= 0; i--){
		if(i == n - 1)
		ccw[i] = a[i].second - (c - a[i].first);
		else
		ccw[i] = ccw[i + 1] + a[i].second - (a[i + 1].first - a[i].first);
		
		if(i == n - 1)
		dp2[i] = ccw[i];
		else
		dp2[i] = max(dp2[i + 1], ccw[i]);
		
		res = max(res, ccw[i]);
	}
	
	//for each i
	//find ccw[j] i < j < n such that cw[i] + ccw[j] - a[i].first is maximize
	//max ccw[j]
	
	for(int i = 0; i < n - 1; i++)
	res = max(res, cw[i] + dp2[i + 1] - a[i].first);
	for(int i = n - 1; i >= 1; i--)
	res = max(res, ccw[i] + dp1[i - 1] - (c - a[i].first));
	
	printf("%lld\n", res);
}
