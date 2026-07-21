#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

main(){
	int n; cin >> n;
	ll arr[n];
	for(int i = 0;i<n;++i) cin >> arr[i];
	for(int i=0;i<n-1;++i){
		if(arr[i]<0){
			arr[i] = -1LL*arr[i];
			arr[i+1] = -1LL*arr[i+1];
		}
	}
	int sum = 0;
	ll total = 0;
	//for(int i=0;i<n;i++) cout << arr[i] << " ";
	//cout << endl;
	for(int i=0;i<n;++i){
		if(arr[i]<0){
			sum++; arr[i] = -1LL*arr[i];
		}
		total += arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<sum;++i) {
		total -= 2LL*arr[i];
	}
	cout << total << endl;
}
