#include <bits/stdc++.h>
using namespace std;

int n;
long long A[100001];

int main(){
	cin>>n;
	int neg=0;
	long long lo=1000000001;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		if(A[i]<0){
			neg++;
		}
		lo=min(lo, abs(A[i]));
		ans+=abs(A[i]);
	}
	if(neg%2==0){
		cout<<ans<<endl;
	}else{
		cout<<ans-lo-lo<<endl;
	}
	
}
