//============================================================================
// Name        : d.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	int mina=2e9;
	long long ans=0;
	int count=0;
	int flag=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)flag=1;
		if(a[i]<0){
			a[i]=-a[i];
			count++;
		}
		mina=min(mina,a[i]);
		ans+=a[i];
	}
	if(flag==0){
		if(count%2){
			ans-=2*mina;
		}
	}

	cout<<ans<<endl;
	return 0;
}
