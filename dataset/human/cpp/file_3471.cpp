#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	vector<long long> num(n);

	long long minus=0;
	long long sum=0;
	long long low=inf;

	for(long long i=0;i<n;i++){
		cin>>num.at(i);
		if(num.at(i)<0) minus++;
		sum+=abs(num.at(i));
		low=min(low,abs(num.at(i)));
	}

	if(minus%2==0) cout<<sum<<endl;
	else cout<<sum-low*2<<endl;

	return 0;
}
