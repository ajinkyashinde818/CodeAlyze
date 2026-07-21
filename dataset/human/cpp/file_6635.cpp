#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,ans=1;
string s;
int main(){
	cin>>n>>s;
	int Left=0;
	for(int i=0;i<s.size();i++){
		int v=s[i]=='B';
		if(v==Left%2){
			//Right
			if(Left==0){
				puts("0");
				return 0;
			}
			ans=(long long)ans*Left%mod;
			Left--;
		}else{
			//Left
			Left++;
		}
	}
	if(Left!=0){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=(long long)ans*i%mod;
	}
	cout<<ans<<endl;
	return 0;
}
