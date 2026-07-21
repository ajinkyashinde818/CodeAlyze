#include<bits/stdc++.h>
using namespace std;

long long n,ans,mod=1e9+7ll,cont;
string s;
int main(){

	cin>>n>>s;
	ans=1;
	if(s[0]=='W' || s[2*n-1]=='W'){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=0;i<s.size();i++){
		if(int(s[i]=='W')==(i%2))cont++;
		else{
			
			if(cont==0){
				cout<<0<<endl;
				return 0;
			}
			
			ans*=cont;
			cont--;
			ans%=mod;
		}
	}
	
	if(cont!=0){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	
	cout<<ans<<endl;

return 0;
}
