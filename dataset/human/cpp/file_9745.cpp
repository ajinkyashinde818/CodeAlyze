#include <bits/stdc++.h>
using namespace std;

int main(){
	long long ans=1;
	int n;
	cin>>n;
	char s[n];
	cin>>s;
	int a[26]={};
	for(int i=0;i<n;i++){
		a[(int)s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		ans*=(a[i]+1);
		ans%=1000000007;
	}
	cout<<ans-1<<endl;
	return 0;
}
