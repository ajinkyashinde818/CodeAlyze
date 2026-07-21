#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAX_N=2*100000;
long long n,a[MAX_N],s=0,sum=0,MIN=2*1000000000;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	
	for(int i=0;i<n-1;i++){
		s+=a[i];
		MIN=min(MIN,abs(s-(sum-s)));
	}
	
	cout << MIN << endl;
	return 0;
}
