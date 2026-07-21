#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long  a[100000];
	int mainasu = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]<0){
			mainasu++;
		}
	}
	long long  ans=0;
	long long mins = abs(a[0]);
	for(int i=0;i<n;i++){
		ans = ans + abs(a[i]);
		mins = min(mins,abs(a[i]));
	}
	if(mainasu%2==1){
		ans = ans-mins*2;
	}
	cout << ans << endl;
}
