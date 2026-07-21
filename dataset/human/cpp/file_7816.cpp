#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long long> a(n);
	
	long long sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	
	long long ans=INF,sum_2=0;
	
	for(int i=0;i<n-1;i++){
		sum_2+=a[i];
		sum-=a[i];
		ans=min(ans,abs(sum-sum_2));
	}
	cout << ans << endl;
	return 0;
}
