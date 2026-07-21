/*
*author : alfarelzaki
*created : 27.04.2019
*/
#include <bits/stdc++.h>
using namespace std;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ct=0;
	long long sum=0;
	bool nol=0;
	cin >> n;
	vector<int>v;
	for (int i=0; i<n; i++){
		int x;
		cin >> x;
		if (x<=0) ct++;
		if (x!=0) v.push_back(abs(x));
		else nol=1;
		sum+=abs(x);
	}

	sort(v.begin(),v.end());
	if (ct%2==0 || nol==1) cout << sum << "\n";
	else cout << sum-2*v[0] << "\n";
}
