#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm>
using namespace std;
int main(){
	int n;
	vector<long long> a;
	long long x;
	long long ncount=0;
	cin >>n;
	for(int i=0;i<n;i++){
		cin >> x;
		if (x<0){
			ncount++;
		}
		x=abs(x);
		a.push_back(x);
	
		
	}
	long long sum=0;
	sort(a.begin(),a.end());
	for (int j=0;j<n;j++){
		sum+=a[j];
	}

	if((ncount%2)!= 0){
	
		
	  	if (a[0]> 0){
	  		
	  		sum=sum-(2*a[0]);
	  	}
	
	}
	cout <<sum <<endl;
	
	return 0;
}
