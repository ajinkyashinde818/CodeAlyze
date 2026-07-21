#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,mina=1e9;
	long long sum=0;
	bool par=false;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=abs(a[i]);
		mina=min(mina,abs(a[i]));
		par^=signbit(a[i]);
	}
	cout<<(par?sum-mina*2:sum)<<endl;
}
