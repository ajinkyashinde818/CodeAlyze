#include <bits/stdc++.h>
using namespace std;

string alfabeto="abcdefghijklmnopqrstuvwxyz";

int mod=1000000007;

long long potencias[100009];

long long dp[26][30];

long long res=0;

map<char, int> freq;


long long solve(int n, int acumulado){
	if (n==26){
		return 1;
	}

	if (dp[n][acumulado]!=-1) return dp[n][acumulado];
	
	dp[n][acumulado]=(solve(n+1,acumulado)+solve(n+1, acumulado+1)*freq[alfabeto[n]])%mod;
	
	
	//cout<<n<<" "<<acumulado<<" "<<dp[n][acumulado]<<endl;
	
	return dp[n][acumulado];
	
}




int main(){
	memset(dp, -1, sizeof(dp));
	
	potencias[0]=1;
	
	for (int i=1; i<100009; i++){
		potencias[i]=(potencias[i-1]*2)%mod;
	}
	
	
	
	int a;
	cin>>a;
	
	
	string s;
	cin>>s;
	
	
	
	//int respeticoes=0;
	
	
	//long long ans=0;
	
	for (int i=0; i<a; i++){
		freq[s[i]]++;
	}
	
	
	cout<<solve(0,0)-1<<endl;
	
	
	

}
