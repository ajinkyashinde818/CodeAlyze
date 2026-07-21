#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	long long int n,ans=0,min=100000000;
	int flag=0;
	
	cin >> n;
	
	vector<int> a(n);
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	
	for(int i=0;i<n;i++){
		if( 0 > a[i] ){
			if(flag==0)flag=1;
			else flag=0;
		}
		a[i] = abs(a[i]);
		if(min > a[i])min = a[i];
	}
	
	
	for(int i=0;i<n;i++){
		ans += a[i];
	}
	
	if(flag==1)ans = ans - 2*min;
	
	cout << ans << endl;
	
	return 0;
}
