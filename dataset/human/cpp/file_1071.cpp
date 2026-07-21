#include<bits/stdc++.h>
using namespace std;
int f[3005],a[3];
signed main(){
	f[0]=1;
	int n;
	cin>>a[0]>>a[1]>>a[2]>>n;
	for(int i=0;i<3;++i){
		for(int j=a[i];j<=n;++j)
			f[j]+=f[j-a[i]];
	} 
	cout<<f[n];
	return 0;
}
