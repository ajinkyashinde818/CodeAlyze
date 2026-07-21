#include <bits/stdc++.h>
using namespace std;
void open() {
	freopen("datain.txt","r",stdin);
}
long long suml[200005],sumr[200005]; 
long long arr[200005];
int n;
long long dif=1e9+1;

int main() {
	//open();	
	cin>>n;
	for (int i=0;i<n;++i) cin>>arr[i];
	if (n==2) dif=abs(arr[1]-arr[0]);
	else {	
	suml[0]=arr[0];
	for (int i=1;i<n-1;++i) suml[i]=suml[i-1]+arr[i];
	//for (int i=0;i<n;++i) cout<<suml[i]<<endl;
	sumr[0]=arr[n-1];
	for (int i=n-2,j=1;i>0;--i,++j) sumr[j]=arr[i]+sumr[j-1];
	//for (int i=0;i<n;++i) cout<<sumr[i]<<endl;
	for (int i=0,j=n-2;i<n-1;++i,--j) {
		if (dif>abs(suml[i]-sumr[j])) dif=abs(suml[i]-sumr[j]);
		//cout<<suml[i]<<"  "<<sumr[j]<<" "<<dif<<endl;
	}
	}
	cout<<dif<<endl;
	return 0;
}
