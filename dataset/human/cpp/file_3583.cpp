#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	long ans=0;
	for(int i=0;i<n;i++) cin >> a[i];
	
	for(int i=0;i<n;i++) ans+=abs(a[i]);
	int m=1e9;
	for(int i=0;i<n-1;i++){
		m=min(m,abs(a[i]));
		if(a[i]<0) a[i+1]=-a[i+1];
	}
	m=min(m,abs(a[n-1]));
	if(a[n-1]<0) cout << ans-2*m << endl;
	else cout << ans << endl;
}
