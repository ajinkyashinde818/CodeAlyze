#include <bits/stdc++.h>
using namespace std;

long long MOD=1000000007LL;

int main(){
	int N;
	string S;
	cin >> N >> S;
	
	if(S[0]=='W' || S[2*N-1]=='W'){
		cout << "0" << endl;
		return 0;
	}
	
	vector<int> SS(2*N);
	for(int i=0;i<2*N;i++){
		if(S[i]=='W')SS[i]=0;
		else SS[i]=1;
	}
	
	vector<int> A(2*N);
	A[0]=1;
	long long ans=1;
	int c=1;
	int use1=1,use2=0;
	for(int i=1;i<2*N-1;i++){
		if(A[i-1]==1 && (c%2)!=SS[i]){
			A[i]=1;
			c++;
			use1++;
			if(use1>N)ans=0;
		}
		else if(A[i-1]==1 && (c%2)==SS[i]){
			A[i]=2;
			ans*=c;
			ans%=MOD;
			c--;
			use2++;
			if(use2>use1)ans=0;
		}
		else if(A[i-1]==2 && (c%2)==SS[i]){
			A[i]=2;
			ans*=c;
			ans%=MOD;
			c--;
			use2++;
			if(use2>use1)ans=0;
		}
		else if(A[i-1]==2 && (c%2)!=SS[i]){
			A[i]=1;
			c++;
			use1++;
			if(use1>N)ans=0;
		}
		//cout << ans << endl;
		if(ans==0)break;
	}
	if(use1!=N || use2!=(N-1))ans=0;
	for(int i=1;i<=N;i++){
		ans*=i;
		ans%=MOD;
	}
	cout << ans << endl;
	return 0;
}
