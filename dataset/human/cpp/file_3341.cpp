#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long mi=0,n,ans=0;
	cin >> n;
	vector<long long> vec(n,0);
	for(int i=0;i<n;i++){
		cin >> vec[i];
		if(vec[i]<0)mi++;
		vec[i]=abs(vec[i]);
		ans+=vec[i];
	}
	sort(vec.begin(),vec.end());
	if(mi%2==1)ans-=2*vec[0];
	cout << ans;
}
