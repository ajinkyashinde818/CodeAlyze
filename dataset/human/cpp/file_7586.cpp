#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	long long ans=pow(10,17);
	long long sum=0;
	long long snuke=0;
	vector<int> card(n);

	for(int i=0;i<n;i++){
		cin>>card.at(i);
		sum+=card.at(i);
	}

	for(int i=0;i<n-1;i++){
		sum-=card.at(i);
		snuke+=card.at(i);
		ans=min(ans,abs(sum-snuke));
	}

	cout<<ans<<endl;

	return 0;
}
