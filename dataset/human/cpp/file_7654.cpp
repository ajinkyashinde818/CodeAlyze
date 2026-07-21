#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>

using namespace std;

typedef long long ll;

int main() {
	int n; cin >> n;

	int a[n];
	ll x,y=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(i!=0) y+=a[i];
	}
	x=a[0];

	ll sub=abs(x-y);
	ll tmp;
	for(int i=1;i<n-1;i++){
		x+=a[i]; y-=a[i];
		tmp = abs(x-y);
		sub = min(sub,tmp);
	}
	cout << sub << "\n";
	return 0;
}
