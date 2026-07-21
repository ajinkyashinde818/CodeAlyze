#include <iostream>

using namespace std;

const int MOD = 1000000007;

int main(){
	
	int n;
	string en;
	cin>>n>>en;
	long long res = 1;
	long long op = 0;
	for(int i=0;i<2*n;i++){
		if(en[i]=='B'){
			if(op%2){
				res = (res*op)%MOD;
				op--;
			}
			else{
				op++;
			}
		}
		else{
			if(op%2){
				op++;
			}
			else{
				if(op==0){
					cout<<0<<endl;
					return 0;
				}
				res = (res*op)%MOD;
				op--;
			}
		}
	}
	if(op){
		cout<<0<<endl;
		return 0;
	}
	while(n){
		res = (res * n)%MOD;
		n--;
	}
	cout<<res<<endl;
		
	return 0;
}
