#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int ans=0;
	int n,b=0;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a.at(i);
		if(a.at(i)<0){
			b++;
			a.at(i)=(-1)*a.at(i);
			ans+=a.at(i);

		}else{
			ans+=a.at(i);
		}
	}
	sort(a.begin(),a.end());
	if(b%2){
		ans-=2*a.at(0);
	}
	cout << ans << endl;	
}
