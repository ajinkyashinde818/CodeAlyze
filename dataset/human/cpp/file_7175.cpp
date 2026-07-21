#include<iostream>
#include "string"

using namespace std;
long int N,a[200000],A,B,ans;

int abs(int x){
	if(x<0){
		return -x;
	}
	return x;
}
 
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
		A+=a[i];
	}
	ans=10000000000000;
	for(int i=0;i<N-1;i++){
		B+=a[i];
		if(abs(A-(2*B))<ans){
			ans=abs(A-(2*B));
		}
	}
	cout<<ans;
	return 0;
}
