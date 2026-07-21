#include<bits/stdc++.h>
using namespace std;
long long a[200001]={0};
long long mina=1000000000000000;
int n,x;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=a[i-1]+x;
	}
	for(int i=1;i<n;i++){
		mina=min(abs(a[n]-2*a[i]),mina);
	}
	cout<<mina<<endl;
}
