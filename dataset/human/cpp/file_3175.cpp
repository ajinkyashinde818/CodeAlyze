#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	int N;
	cin >> N;
	vector<long long> A(N);
	for(int i=0;i<N;i++)	cin >> A.at(i);

	long long ans=0;
	long long mi=1e9;
	int count=0;
	int count0=0;
	for(int i=0;i<N;i++){
		ans+=abs(A.at(i));
		mi=min(mi,abs(A.at(i)));
		if(A.at(i)<0)	count++;
		else if(A.at(i)==0)	count0++;
	}
	if(count0>0)	cout << ans << endl;
	else if(count%2==0)	cout << ans << endl;
	else	cout << ans-2*mi << endl;

	return 0;
}
