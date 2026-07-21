#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N, left=0, right=0, ans=2e9;
    cin >> N;
    vector<long long> a(N);
    for(int i=0; i<N; i++){
	cin >> a[i];
	right += a[i];
    }

    for(int i=0; i<N-1; i++){
	left += a[i];
	right -= a[i];
	ans = min(ans, abs(right-left));
    }

    cout << ans << endl;


}
