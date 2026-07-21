#include<iostream>
#include<vector>
using namespace std;
const int mod=1e9+7;
int cnt[27];
int main(){
	int n,i,j,k,sum=0;
	long long tich=1;
	string s;
	cin>>n>>s;
	for(i=0;i<s.size();i++){
		cnt[(s[i]-'a'+1)]++;
	}
	for(i=1;i<=26;i++){
		tich*=(cnt[i]+1);
		tich%=mod;
	}
	cout<<tich-1;
}
