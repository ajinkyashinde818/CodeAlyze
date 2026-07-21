#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[200200], b[200200], cnt[200200], cnt2[200200], chk[200200], cnt3[200200];
priority_queue<pair<int, int>> A, B;
queue<int> q[200200];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];

	for(int i=1;i<=n;i++) cnt[a[i]]++, cnt[b[i]]++;

	for(int i=1;i<=n;i++) if(cnt[i] > n){
		cout << "No";
		return 0;
	}

	for(int i=1;i<=n;i++) chk[a[i]] = 1;
	for(int i=1;i<=n;i++) if(chk[i]) A.push({cnt[i], i});

	for(int i=1;i<=n;i++) cnt2[b[i]]++;
	for(int i=1;i<=n;i++) if(cnt2[i]) B.push({cnt[i], i});

	for(int i=1;i<=n;i++) cnt3[a[i]]++;

	auto u = A.top().second; A.pop();
	int mx = 0;

	for(int i=1;i<=n;i++){
		if(cnt2[mx]) B.push({cnt[mx], mx});
		mx = B.top().second, B.pop();

		if(B.empty() || mx != u){
			// cout << 1 << " " << u.second << " " << mx.second << "\n";
			q[u].push(mx);
			--cnt2[mx];
			--cnt[mx];
		}else{
			auto k = B.top().second; B.pop();
			// cout << 2 << " " << u.second << " " << k.second << "\n";
			q[u].push(k);
			--cnt2[k];
			--cnt[k];
			if(cnt2[k]) B.push({cnt[k], k});
		}

		--cnt3[u];
		--cnt[u];
		if(cnt3[u]) A.push({cnt[u], u});
		u = A.top().second, A.pop();
	}

	cout << "Yes\n";
	for(int i=1;i<=n;i++){
		cout << q[a[i]].front() << " ";
		q[a[i]].pop();
	}
}
