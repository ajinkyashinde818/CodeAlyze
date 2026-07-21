#include<iostream>
#include<vector>
#include<string>

int main(){
	long long mod= 1000000007;
	long long ans= 0;

	int n;
	std::string s;
	std::vector<long long> alpList(26, 0);

	std::cin>>n;
	std::cin>>s;

	for(int i=0; i<n; i++)
		alpList[s[i]-'a']++;

	for(int i=0; i<26; i++){
		ans= (ans+ ans*alpList[i])%mod;
		ans= (ans+ alpList[i])%mod;
	}

	std::cout<<ans<<std::endl;
}
