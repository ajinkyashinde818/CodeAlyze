#include<bits/stdc++.h>
using namespace std;
int N;
long long x,sum,mmin=2e9,cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; ++i){
		cin >> x;
		sum += abs(x);
		mmin = min(mmin,abs(x));
		if(x < 0) cnt++;
	}
	if(cnt % 2 == 1) sum -= mmin*2;
	cout << sum << endl;
	return 0;
}
