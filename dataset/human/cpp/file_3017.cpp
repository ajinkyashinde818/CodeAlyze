#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <stack>
#include <queue>

typedef long long ll;

using namespace std;

int main(void){
	int n; cin >>n;
	int a[100001];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	ll sum=0;
	int count=0, min_a=INT_MAX;
	for(int i=0; i<n; i++){
		sum += abs(a[i]);
		min_a = min(min_a, abs(a[i]));
		if(a[i] < 0) count++;
	}
	if(count%2 == 1)sum -= 2*abs(min_a);

	cout << sum << endl;
	
	return 0;
}
