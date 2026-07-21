#include<bits/stdc++.h>
using namespace std;
int a[200100];
long long tot;
long long qzh;
int n;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i];
	}
	long long res=1e18;
	for(int i=1;i<=n-1;i++){
		qzh+=a[i];
		res=min(res,llabs(tot-qzh-qzh));
	}
	cout<<res<<endl;
	return 0;
}
