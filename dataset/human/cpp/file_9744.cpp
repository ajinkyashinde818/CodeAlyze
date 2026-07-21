#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;
 

int main(){
	long long N,ans=1,X[26]={}; cin >> N;
	string S; cin >> S;
	for(int i=0; i<N; i++){
		for(int j=0; j<26; j++){
			if(S[i]=='a'+j) X[j]+=1;
		}
	}
	for(int i=0; i<26; i++){
		ans*=X[i]+1;
      ans%=1000000007;
	}
	cout << ans-1 << endl;
}
