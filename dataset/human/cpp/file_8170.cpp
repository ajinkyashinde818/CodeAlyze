#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<long long> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	long long ans=abs((a[n]-a[1])-a[1]);
	for(int i=2;i<n;i++){
		ans=min(ans,abs((a[n]-a[i])-a[i]));
	}
	cout << ans << endl;
}
