#include<bits/stdc++.h>
using namespace std;

main(){
	int n; cin>>n;
	
	int a[n], b[n];
	for(auto &it : a) cin>>it;
	for(auto &it : b) cin>>it;
	
	reverse(b, b+n);
	
	int c, l=0, r=-1;
	for(int i=0; i<n; i++){
		if(a[i]==b[i]){
			c = a[i];
			l = i;
			break;
		}
	}
	for(int i=n-1; i>=0; i--){
		if(a[i]==c && b[i]==c){
			r = i;
			break;
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]!=c && b[i]!=c && l<=r){
			swap(b[i],b[l]);
			l++;
		}
	}
	if(l<=r)  cout<<"No";
	else{
		cout<<"Yes"<<endl;
		for(int x : b) cout<<x<<" ";
	}
}
