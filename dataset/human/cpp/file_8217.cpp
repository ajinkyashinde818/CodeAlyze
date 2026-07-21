#include<iostream>
using namespace std;
int main(){
	
	int n,a[222222];
	cin>>n;
	long long x=0,y=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		y+=a[i];
	}
	long long min=1000000000000000000;
	//min=std::min(min,abs(x-y));
	for(int i=0;i<n-1;i++){
		x+=a[i];
		y-=a[i];
		min=std::min(min,abs(x-y));
	}
	cout<<min<<endl;

}
