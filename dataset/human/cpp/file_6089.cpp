#include <bits/stdc++.h>
using namespace std;



int main(){
	long long int N,C;cin>>N>>C;
	vector<long long> locs(N),vals(N),best(N),best2(N),bloc(N),bloc2(N);
	for(int i=0;i<N;i++) cin>>locs[i]>>vals[i];
	for(int i=0;i<N;i++) bloc[i] = bloc2[i] = locs[i];
	best[0] = best2[0] = vals[0];
	for(int i=1;i<N;i++) best[i] = vals[i] + best[i-1];
	for(int i=1;i<N;i++) best2[i] = vals[i] + best2[i-1];
	for(int i=0;i<N;i++) best[i] = best[i] - locs[i];
	for(int i=0;i<N;i++) best2[i] = best2[i] - 2*locs[i];
	for(int i=1;i<N;i++) if(best[i-1] > best[i]){
		best[i] = best[i-1];
		bloc[i] = bloc[i-1];
	}
	for(int i=1;i<N;i++) if(best2[i-1] > best2[i]){
		best2[i] = best2[i-1];
		bloc2[i] = bloc2[i-1];
	}
	long long int ans = max(0LL,best[N-1]),totc = 0;
	for(int i=N-1;i>=0;i--){
		totc += vals[i];
		long long curr = totc - (C - locs[i]);
		//cout<<totc<<" "<<locs[i]<<endl;
		ans = max(ans,curr);
		if(i-1>=0){
			ans = max(ans, curr + best2[i-1]);
			ans = max(ans, curr + best[i-1] - (C-locs[i]));
		}
	}
	cout<<ans<<endl;
}
