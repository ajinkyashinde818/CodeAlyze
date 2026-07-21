#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	long long x=0,y=0,ans=100000000000000000LL;
	cin >>n;
	vector<long long>a(n);
	for(int i=0;i<n;i++){
		cin >>a[i];
		x+=a[i];
	}
	for(int i=0;i<n;i++){
		y+=a[i];
		if(i+1<n){
			ans=min(ans,abs(x-2*y));
			
		}
	
	}
	cout <<ans<<endl;
	
}
